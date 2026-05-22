function [x_obs] = set_next_obs(i_run, x_obs, scan_list, res_err_test, seed)
% Set the hyper-parameters for Bayesian optimisation
% Written by Piotr Antonik, May 2020

    rng(seed, 'twister');
    y_obs = res_err_test;
    x_list = scan_list';

    gp_model = fitrgp(x_obs(1:i_run-1,:), y_obs(1:i_run-1), ...
      'OptimizeHyperparameters', 'auto', ...
      'KernelFunction','squaredexponential', ...
      'HyperparameterOptimizationOptions', struct('ShowPlots', false, 'Verbose', 0, ...
      'AcquisitionFunctionName','expected-improvement-plus') ); % for reproducibility
                     
    [y_best, idx_y_best] = min(y_obs);
%     fprintf('Best observation so far: %f at (%f, %f, %f, %f).\n', y_best, x_obs(idx_y_best,:));
    fprintf('Best observation so far: %f at (%f, %f, %f).\n', y_best, x_obs(idx_y_best,:));
   
    [ei, d_f_mean, d_f_sd] = expected_improvement(x_list, gp_model, y_best);
    x_list_ei = sortrows([x_list ei], -(size(x_list,2)+1));
    new_x_obs_found = 0;
    i_x_obs_new = 1;
    while ~new_x_obs_found
        x_obs_new = x_list_ei(i_x_obs_new, 1:end-1);
        [~, idx_x_obs, ~] = intersect(x_obs, x_obs_new, 'rows');
        if isempty(idx_x_obs)
            new_x_obs_found = 1;
        else
            i_x_obs_new = i_x_obs_new + 1;
%             fprintf('Already checked at (%f, %f, %f, %f), skipping.\n', x_obs_new);
            fprintf('Already checked at (%f, %f, %f), skipping.\n', x_obs_new);
        end
    end
    
    res_ei_max(i_run, :) = [x_list_ei(i_x_obs_new, end), x_obs_new];
    fprintf('Next observation at (%f, %f, %f, %f), %d-th max of EI.\n', x_obs_new, i_x_obs_new);
    
    x_obs(i_run, :) = x_obs_new;

end