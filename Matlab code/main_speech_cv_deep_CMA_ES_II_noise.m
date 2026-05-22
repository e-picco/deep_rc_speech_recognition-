%main code
%written by Enrico PICCO, Jan 2023

%Task: Speech Recogn, no noise
%Training: RIDGE regression
%Scan hyper-parameters: Grid or Bayes

clearvars -except obj_opt_att obj_hameg obj_fpga
addpath(genpath('.'));

% N=200;
Nf=77; %Nf=86 for SNR=0, Nf=77 for SNR=3 (it's the dataset)
K=34107; %K=28384 for SNR=0, K=34107 for SNR=3 (it's the dataset)
train_size=450; %from 0 to 500 
% L_layers=2; 

seed_mask=42;
seed_gauss=43;
seed_data=44;

p.fpga_data_mode='x'; %'x': nrns, 'xy' nrns & outs, 'xw' nrns & weighted nrns, 'xwy' nrns & weighted nrns & outs   
p = def_p(p);
N=p.size_res;
p.fpga_u_amp   = 0.1; % 
p.n_warmup = 0; 

p.lambdas = 100*[0 1e-15 1e-14 1e-13 1e-12 1e-11 1e-10 1e-9 1e-8 1e-7 1e-6 1e-5 1e-4 1e-3 1e-2 1e-1 1];
% p.lambdas = 0; %logspace(-3, 0, 100); %p.lambdas = 100*[0 1e-15 1e-14 1e-13 1e-12 1e-11 1e-10 1e-9 1e-8 1e-7 1e-6 1e-5 1e-4 1e-3 1e-2 1e-1 1];
p.lambdas(1) = 0;    

send_p(p); %set fpga params 
% reset_p_0(p); %reset fpga params to 0

p.optim = 'grid';         % 'grid' search or 'bayes'ian optimisation
p.n_bayes_runs = 50;

%best hp bayes scan (after Triglevel=100)
hp.inp_vals = logspace(-3,1,100);
hp.mzb_vals = linspace(2,4,20);
hp.fdb_vals = linspace(1,8,100);

hp.inp_vals  = 0.0954;
hp.mzb_vals = 4;
hp.fdb_vals = 4.46;

hp.tin_vals = 0; %2100; %100:200:500;
hp.alf_vals = 0.993; %0.990:0.002:0.999;
hp.stp_vals = 0.8;

[scan_params, scan_list, n_runs] = def_scan_params(hp);

if strcmp(p.optim, 'bayes')
    n_scan_params = size(scan_list, 1);
    x_obs_init    = combvec(hp.inp_vals([1,round(end/2),end]), hp.mzb_vals([1,round(end/2),end]), hp.fdb_vals([1, round(end/2),end]))';
%     x_obs_init    = combvec(hp.inp_vals([1, end]), hp.mzb_vals([1, end]), hp.fdb_vals([1, end]))';
    n_init_runs   = size(x_obs_init, 1);
    n_runs        = n_init_runs + p.n_bayes_runs;
    x_obs         = zeros(n_runs, n_scan_params);
    x_obs(1:n_init_runs, :) = x_obs_init;
end

%%%%%%%%%%%%%%%%%%%%%%%LOAD DATASET%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
load('DataSpokenDigit.mat')
data = data_3dBSNR;
% inputs=data.inputs; %  (NfxNk) (86x28384 for noise=0) (77x34107 for noise=3dB)
% targets=data.outputs; %(10xNk) (10x28384 for noise=0) (10x34107 for noise=3dB)

%%%%%%%%%%%%%%%%%%%%%%%SHUFFLE DATASET%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
rng(seed_data)
shuffle_index=randperm(500);

data.SplitVector_shuffled=data.SplitVector(:,shuffle_index); 

inputs_shuffled=zeros(size(data.inputs));   %86x28384 or 77x34107 (NfxNk)
targets_shuffled=zeros(size(data.outputs)); %10x28384 or 10x34107 (10xNk)

data.SplitIndexDigitVector(501)=K+1; %28385 or 34108
pointer_shuffled=1;
for i=1:500
    digit_start = data.SplitIndexDigitVector(shuffle_index(i));   %12383
    digit_end = data.SplitIndexDigitVector(shuffle_index(i)+1)-1; %12452
    digit_length(i) = digit_end-digit_start+1;                       %70
    digit_inputs = data.inputs(:,digit_start:digit_end);
    digit_targets = data.outputs(:,digit_start:digit_end);
    
    data.SplitIndexDigitVector_shuffled(i)=pointer_shuffled;
    inputs_shuffled(:,pointer_shuffled:pointer_shuffled+digit_length(i)-1) = digit_inputs;
    targets_shuffled(:,pointer_shuffled:pointer_shuffled+digit_length(i)-1) = digit_targets;
    pointer_shuffled = pointer_shuffled + digit_length(i);
end
data.SplitVector = data.SplitVector_shuffled;
data.SplitIndexDigitVector = data.SplitIndexDigitVector_shuffled;
inputs_shuffled=p.fpga_u_amp*inputs_shuffled;
%%%%%%%%%%%%%%%%%%%%%%%%%%%% MASK %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
rng(seed_mask)
d.mask_input = 2*rand(N,Nf) - 1; %NxNf %IN SIM
% d.mask_input = 2*rand(N,1) - 1; %NxNf    %IN EXP

%%%%%%%%%%%%%%%%%%%%%%%%%% CMA-ES Initialization %%%%%%%%%%%%%%%%%%%%%%%%%%
figure(1); hold off;
plot_idx = 1;

% --------------------  Initialization --------------------------------
% User defined input parameters (need to be edited)
N_cma = N*N;               % number of objective variables/problem dimension
xmean = 2*rand(N_cma,1)-1;    % objective variables initial point
sigma = 0.3;          % coordinate wise standard deviation (step size)
stopfitness = 1e-10;  % stop if fitness < stopfitness (minimization)
stopeval = 1e3*N_cma^2;   % stop after stopeval number of function evaluations

% Strategy parameter setting: Selection
lambda = 4+floor(3*log(N_cma));  % population size, offspring number
mu = lambda/2;               % number of parents/points for recombination
weights = log(mu+1/2)-log(1:mu)'; % muXone array for weighted recombination
mu = floor(mu);
weights = weights/sum(weights);     % normalize recombination weights array
mueff=sum(weights)^2/sum(weights.^2); % variance-effectiveness of sum w_i x_i

% Strategy parameter setting: Adaptation
cc = (4+mueff/N_cma) / (N_cma+4 + 2*mueff/N_cma);  % time constant for cumulation for C
cs = (mueff+2) / (N_cma+mueff+5);  % t-const for cumulation for sigma control
c1 = 2 / ((N_cma+1.3)^2+mueff);    % learning rate for rank-one update of C
cmu = min(1-c1, 2 * (mueff-2+1/mueff) / ((N_cma+2)^2+mueff));  % and for rank-mu update
damps = 1 + 2*max(0, sqrt((mueff-1)/(N_cma+1))-1) + cs; % damping for sigma
% usually close to 1
% Initialize dynamic (internal) strategy parameters and constants
pc = zeros(N_cma,1); ps = zeros(N_cma,1);   % evolution paths for C and sigma
B = eye(N_cma,N_cma);                       % B defines the coordinate system
D = ones(N_cma,1);                      % diagonal D defines the scaling
C = B * diag(D.^2) * B';            % covariance matrix C
invsqrtC = B * diag(D.^-1) * B';    % C^-1/2
eigeneval = 0;                      % track update of B and D
chiN=N_cma^0.5*(1-1/(4*N_cma)+1/(21*N_cma^2));  % expectation of
%   ||N_cma(0,I)|| == norm(randn(N_cma,1))
% -------------------- Generation Loop --------------------------------
counteval = 0;  % the next 40 lines contain the 20 lines of interesting code
countiter=0;

%%%%%%%%%%%%%%%%%%%%%%%%%%%% EXPERIMENT %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
WER_err_train = ones(n_runs, 1);   % training error (results)
WER_err_test  = ones(n_runs, 1);   % testing error (results)
best_WER_test = 1;

for i_run=1:n_runs
    tic
    if strcmp(p.optim, 'grid')
        hp = set_cur_params_to_devices(i_run, n_runs, hp, scan_params, scan_list, obj_opt_att, obj_hameg ); % set HP values of current run to devices
    elseif strcmp(p.optim, 'bayes')
        if i_run>n_init_runs
            x_obs = set_next_obs(i_run, x_obs, scan_list, WER_err_test, seed_gauss);
        end
        hp = set_cur_params_to_devices(i_run, n_runs, hp, scan_params, x_obs', obj_opt_att, obj_hameg ); % set HP values of current run to devices
    end


    % while counteval < stopeval
    while counteval < 100000*lambda

        countiter=countiter+1;
        fprintf('ITERATION %.0d: \n', countiter);

        %%%%%%%%%%%%%%%%%%%%%%% RUN RESERVOIR 1 %%%%%%%%%%%%%%%%%%%%%%%%%%%
        reservoir_1=zeros(N, K); %Nx28384 or Nx34107
        data.SplitIndexDigitVector(501)=K+1; %28385 or 34108

        %         load('best_reservoir_bayes_noise.mat')
        load('new_opt_point_100_2.mat')
        reservoir_1 = best_reservoir_bayes(1:100,:);
        %%%%%%%%%%%% RUN RESERVOIR 2 with OPTIMIZED INTERLAYER MASK %%%%%%%%%

        % Generate and evaluate lambda offspring
        for k=1:lambda
            rng(k)
            arx(:,k) = xmean + sigma * B * (D .* randn(N_cma,1)); % m + sig * Normal(0,C)

            %%%%%%%%%%%%%%%%%%%%%%%  INTERLAYER MASK  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %         mask_inter_layer=2*rand(N,N)-1;%NxN
            mask_inter_layer = arx(1:N_cma, k)'; %
            mask_inter_layer = reshape(mask_inter_layer,N,N); %NxN

            inputs_2 = mask_inter_layer*reservoir_1; %NxK

            reservoir_2=zeros(N, K); %Nx28384 or Nx34107

            p.n_inputs=200; send_p(p); %the input size used by the fpga is the time-length of a single digit (similar to the 10 timeframes used for HAR)
            for i=1:170 %(DIGITS ARE NOT DIVIDED ANYMORE NOW)
%                 fprintf('Run %3.0f/%d. Layer 2. "Audio-reservoir" sample %3.0f/171.\n', i_run, n_runs, i);
                digit_start = (i-1)*200+1;
                digit_end = i*200; %
                digit_length_2(i) = 200;
                digit_inputs = inputs_2(:,digit_start:digit_end); %100 x 200
                %         inputs_masked = d.mask_input*digit_inputs;               %N  x ??
                digit_inputs=reshape(digit_inputs, 1, []); %1x(20000)
                p.fpga_u_amp   = 1/max(abs(digit_inputs));
                digit_inputs= 0.9*p.fpga_u_amp*digit_inputs;
                fpga_send_data(digit_inputs, hp.inp*ones(1,p.size_res));
                [d.x_digit, ~, ~] = fpga_run(p); %N100x200
                reservoir_2(:,digit_start:digit_end)=d.x_digit; %N100x200
            end
            %last "digit"
            p.n_inputs=107; send_p(p);
            i=171;
%             fprintf('Run %3.0f/%d. Layer 2. "Audio-reservoir" sample %3.0f/171.\n', i_run, n_runs, i);
            digit_start = (i-1)*200+1;
            digit_end = K; %
            digit_length_2(i) = digit_end-digit_start+1; %107
            digit_inputs = inputs_2(:,digit_start:digit_end); %100 x 107
            %         inputs_masked = d.mask_input*digit_inputs;               %N  x ??
            digit_inputs=reshape(digit_inputs, 1, []); %1x(10700)
            p.fpga_u_amp   = 1/max(abs(digit_inputs));
            digit_inputs= 0.9*p.fpga_u_amp*digit_inputs;
            fpga_send_data(digit_inputs, hp.inp*ones(1,p.size_res));
            [d.x_digit, ~, ~] = fpga_run(p); %100x107
            reservoir_2(:,digit_start:digit_end)=d.x_digit; %N100x107

            reservoir = [reservoir_1; reservoir_2]; %(2*N)xK with N=100 -->

            %%%%%%%%%%%%%%%%%%%%%%%%%CREATE CV SETS%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            inputs_cv = zeros([size(inputs_shuffled) 10]); %86x28384x10
            targets_cv = zeros([size(targets_shuffled) 10]); %10x28384x10
            SplitVector_cv = zeros([size(data.SplitVector) 10]); %3x500x10
            SplitIndexDigitVector_cv = zeros([size(data.SplitIndexDigitVector) 10]); %1x500x10
            reservoir_cv = zeros([size(reservoir) 10]); %(2*N)x28384x10

            [reservoir_cv, targets_cv, SplitVector_cv, SplitIndexDigitVector_cv] = generate_cv_sets_exp(reservoir, inputs_shuffled, targets_shuffled, data, digit_length);

            for kf = 1:10
                reservoir_kfold=reservoir_cv(:,:,kf);
                targets_kfold=targets_cv(:,:,kf);
                data.SplitVector=SplitVector_cv(:,:,kf);
                data.SplitIndexDigitVector=SplitIndexDigitVector_cv(:,:,kf);
                %%%%%%%%%%%%%%%%%%%%%%%%%%%TRAIN%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                [WER_train_cv(i_run,kf), WER_test_cv(i_run,kf), ~, ~, ~] = train_eval_rc(p, reservoir_kfold, targets_kfold, data, train_size); % train reservoir computer
            end

            %%average the K-folds results
            WER_err_train(i_run) = mean(WER_train_cv(i_run,:));
            WER_err_test(i_run) = mean(WER_test_cv(i_run,:));

            arfitness(k) = WER_err_test(i_run);
            fprintf('Offspring %.0d: Train error: %.2e, Test error: %.2e. \n', k, WER_err_train(i_run), WER_err_test(i_run));

            if WER_err_test(i_run) < best_WER_test
                best_WER_test = WER_err_test(i_run);
                best_WER_test_cv = WER_test_cv(i_run,:);
                best_reservoir = reservoir;
                best_interlayer_mask = mask_inter_layer;
                best_offspring=k;
                best_iter = countiter;
                save(['WER_N_' num2str(N), '_L_2_CMA_ES_temp.mat' ], 'best_WER_test', 'best_WER_test_cv', 'best_reservoir', 'best_interlayer_mask', 'best_offspring', 'best_iter' );
            end

            counteval = counteval+1;
        end

        % Sort by fitness and compute weighted mean into xmean
        [arfitness, arindex] = sort(arfitness); % minimization
        xold = xmean;
        xmean = arx(:,arindex(1:mu))*weights;   % recombination, new mean value

        % Aggiorna il plot
        figure(1);
        %     	W_freq = arx(1:50, arindex(1))';
        sc=arfitness(1);
        scatter(plot_idx, sc, 'ko'); hold on;
        plot_idx=plot_idx + 1;
        set(gca, 'YScale', 'log');
        drawnow;

        % Cumulation: Update evolution paths
        ps = (1-cs)*ps ...
            + sqrt(cs*(2-cs)*mueff) * invsqrtC * (xmean-xold) / sigma;
        hsig = norm(ps)/sqrt(1-(1-cs)^(2*counteval/lambda))/chiN < 1.4 + 2/(N_cma+1);
        pc = (1-cc)*pc ...
            + hsig * sqrt(cc*(2-cc)*mueff) * (xmean-xold) / sigma;

        % Adapt covariance matrix C
        artmp = (1/sigma) * (arx(:,arindex(1:mu))-repmat(xold,1,mu));
        C = (1-c1-cmu) * C ...                  % regard old matrix
            + c1 * (pc*pc' ...                 % plus rank one update
            + (1-hsig) * cc*(2-cc) * C) ... % minor correction if hsig==0
            + cmu * artmp * diag(weights) * artmp'; % plus rank mu update

        % Adapt step size sigma
        sigma = sigma * exp((cs/damps)*(norm(ps)/chiN - 1));

        % Decomposition of C into B*diag(D.^2)*B' (diagonalization)
        if counteval - eigeneval > lambda/(c1+cmu)/N_cma/10  % to achieve O(N_cma^2)
            eigeneval = counteval;
            C = triu(C) + triu(C,1)'; % enforce symmetry
            [B,D] = eig(C);           % eigen decomposition, B==normalized eigenvectors
            D = sqrt(diag(D));        % D is a vector of standard deviations now
            invsqrtC = B * diag(D.^-1) * B';
        end

        % Break, if fitness is good enough or condition exceeds 1e14, better termination methods are advisable
        if arfitness(1) <= stopfitness || max(D) > 1e7 * min(D)
            break;
        end
    end
end 

% list all scans, sort by performance
if strcmp(p.optim, 'grid')
    res_list      = [1:n_runs; scan_list; WER_err_train'; WER_err_test'];
elseif strcmp(p.optim, 'bayes')
    res_list      = [1:n_runs; x_obs'; WER_err_train'; WER_err_test'];
end
res_list_srtd = sortrows(res_list', size(res_list,1));

%plot results with standard dev
figure(2)
e=errorbar(1:n_runs, WER_err_test, std(WER_test_cv'));
e.Marker = '*';
e.MarkerSize = 6;
e.LineWidth = 2;
e.Color = 'red';
title('Test error with standard deviation');

saveas(gcf,['WER_N_' num2str(N),'_L_2.fig' ])
save(['WER_N_' num2str(N), '_L_2.mat' ], 'hp', 'WER_err_test', 'WER_test_cv', 'reservoir' );
% save(['exp_results_all_' datestr(now, 'yyyy_mm_dd') '.mat']);

% if n_runs==1
%     hold on
%     plot(data.SplitVector(3,train_size+1:end), '-bo')
%     plot(best_out_test, '-rx', 'LineWidth', 2)
%     title('Test error:', WER_err_test)
% end

% save(['res_testerror_' num2str(r.err_test) '.mat'], 'd', 'r');
% save(['res_exp_aro_v04_' p.train '_' num2str(p.n_iter_train) 'iters_' ...
%      num2str(n_runs) 'runs_' datestr(now, 'yyyy_mm_dd') '.mat'], 'p', 'hp', 'r');
