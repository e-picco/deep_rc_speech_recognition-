function [ reservoir, outputs, weighted_states ] = fpga_run(p)
    % Launch train phase on FPGA, return neurons
    % Written by E.Picco, Feb 2022

    switch p.fpga_data_mode
        case 'x', n_nodes = p.n_neurons;
        case 'xy', n_nodes = p.n_neurons + 1;
        case 'xw', n_nodes = 2*p.n_neurons;
        case 'xwy', n_nodes = 2*p.n_neurons + 1;
    end
    
%open READ Xillybus device file
command = 'cat \\.\xillybus_read_32 > data_rx.bin &';
status = system(command); %return 0 if command is succesfull
if status==1; disp('Error: xillybus_read_32 not opened') ; end
    
    wait_4= repmat([118 85],4,1); %wait
    M = [112 0]; %init                                    70 00
    M = [M; 112 1]; 
    M = [M; 112 35; 118 84; 0 p.fake_sw_b; 118 85;wait_4];% 70 23; 76 54; 00 ??; 76 55(x5)
    M = [M; 112 2]; %test                                   70 02  
    %     wait= repmat([0 1],100,1); M = [M; wait]; %wait 50cc (WARNING: up to a certain value, it reaches some Xillybus limit)
    %     M = [M; 112 0]; %init                                    70 00

    % bit stuffing 
    M = flip(M,2);
    M = [M zeros(size(M))];
    M = M'; %because data are read by column

    % save in .bin file
    f = fopen('statetrain_tx.bin', 'w');
    fwrite(f, M, 'uint8');
    fclose(f);

    % write bin file to xillybus device file 
    command = 'cat statetrain_tx.bin > \\.\xillybus_write_32';
    status = system(command); %return 0 if command is succesfull
    if status==1; disp('Error: Traine phase command not sent') ; end

% wait and open data from fpga check bin file
pause(0.3)
% pause(0.03) %ok for 50x5000
f = fopen('data_rx.bin', 'r');
data = fread(f, inf, 'uint8'); % binary file also does not store the matrix dimensions by default
fclose(f);

%close prompt window

system('Taskkill/IM cmd.exe');



data_2 = reshape(data, 4, size(data,1)/4 );
data_3 = data_2(1:2, :);
data_4 = flip(data_3);
data_5 = data_4(1,:)*2^8 + data_4(2,:);
data_5(data_5>2^15) = -(2^16 - data_5(data_5>2^15));
data_6=data_5(1:n_nodes*p.n_inputs);
data_6 = data_6 / 2^15;

reservoir=reshape(data_6, [p.n_neurons, p.n_inputs]);
% reservoir=[reservoir; p.bias_node*ones(1, p.n_inputs)];

outputs = nan(1, p.n_inputs);
weighted_states = nan(p.n_neurons, p.n_inputs);
     
    %set idle state
    M = [112 0]; %init                   
    % bit stuffing 
    M = flip(M,2);
    M = [M zeros(size(M))];
    M = M'; %because data are read by column
    % save in .bin file
    f = fopen('stateidle_tx.bin', 'w');
    fwrite(f, M, 'uint8');
    fclose(f);
    % write bin file to xillybus device file 
    command = 'cat stateidle_tx.bin > \\.\xillybus_write_32';
    status = system(command); %return 0 if command is succesfull
    if status==1; disp('Error: Idle phase command not sent') ; end

end
