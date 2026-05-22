% Initialisation script for the MAIN experimental setup
% To be executed once and first thing after launching Matlab
% Written by Enrico Picco, February 2022

addpath(genpath('.'));

fprintf('Initialising the HAMEG power source...\n');
obj_hameg = hameg_init('COM3');
%ch1 not connected
%ch2 MZ2
%ch3 rf amp
%ch4 MZ1

fprintf('Initialising the Agilent optical attenuator...\n');
%obj_opt_att = opt_att_init('Agilent', 1, 7);
obj_opt_att = InitiateJDSHA9()
SetAttenuationJDSHA9(obj_opt_att,7,0);

