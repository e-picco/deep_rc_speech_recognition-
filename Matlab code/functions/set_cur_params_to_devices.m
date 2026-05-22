function [ hp ] = set_cur_params_to_devices (i_run, n_runs, ...
            hp, scan_params, scan_list, obj_optatt, obj_hameg )

    % assign current parameters values
    for i_hp=1:length(scan_params.vars)
        eval([scan_params.vars{i_hp} '=' num2str(scan_list(i_hp, i_run)) ';']);
    end
    
    % print current parameters
    fprintf('Run %3.0f/%d. ', i_run, n_runs);
    fprintf('In: %.3f, ', hp.inp);
    fprintf('Att: %.2f dB, ', hp.fdb);
    fprintf('MZb: %.2f V.\n', hp.mzb);
    
    % set attenuator
    %opt_att_set_att('Agilent', obj_optatt, 1, hp.fdb);
    SetAttenuationJDSHA9(obj_optatt,hp.fdb,0);
    
    
    % set MZ DC Bias
    hameg_set_volt(obj_hameg, 4, hp.mzb);
end 
