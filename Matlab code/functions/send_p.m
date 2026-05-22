function [] = send_p(p)
    
%% convert param to bytes
smpdelay1_b = [floor(p.smp_dly1/2^8) rem(p.smp_dly1, 2^8) ];
smpdelay2_b = [floor(p.smp_dly2/2^8) rem(p.smp_dly2, 2^8) ];
trigLevel_b = [floor(p.trig_level/2^8) rem(p.trig_level, 2^8) ];
lPat_b      = [floor(p.n_inputs/2^8) rem(p.n_inputs, 2^8) ];
amp_dac_b   = [floor(p.amp_dac/2^8) rem(p.amp_dac, 2^8) ];
wtsdelay_b  = [floor(p.wts_dly/2^8) rem(p.wts_dly, 2^8) ];
max_sampled_data_b = [floor(p.max_sampled_data/2^8) rem(p.max_sampled_data, 2^8) ];
idelay_b    = [floor(p.idelay/2^8) rem(p.idelay, 2^8) ];

wait_4= repmat([118 85],4,1); %wait

M = [112 0]; %init                             70 00   
M = [M; 112 1];                              % 70 01
M = [M; 112 21; 118 84; smpdelay1_b; 118 85;       wait_4];% 70 15; 76 54; 00 1D [29];   76 55(x5) 
M = [M; 112 32; 118 84; smpdelay2_b; 118 85;       wait_4];% 70 20; 76 54; 00 1F [31];   76 55(x5)
M = [M; 112 27; 118 84; trigLevel_b; 118 85;       wait_4];% 70 1B; 76 54; 00 32 [50];   76 55(x5)
M = [M; 112 26; 118 84; 0 p.amp_nrn1; 118 85;      wait_4];% 70 1A; 76 54; 00 05 [5];    76 55(x5)
M = [M; 112 28; 118 84; 0 p.amp_nrn2; 118 85;      wait_4];% 70 1C; 76 54; 00 05 [5];    76 55(x5)
M = [M; 112 22; 118 84; lPat_b; 118 85;            wait_4];% 70 16; 76 54; 13 88 [5000]; 76 55 (N=500=[1 244])
M = [M; 112 29; 118 84; amp_dac_b ;118 85;         wait_4];% 70 1d; 76 54; 00 00 [0] ;   76 55 [0 0]
M = [M; 112 33; 118 84; wtsdelay_b;118 85;         wait_4];% 70 21; 76 54; 00 24 [36];   76 55 [0 36] 
M = [M; 112 36; 118 84; max_sampled_data_b; 118 85;wait_4];% 70 24; 76 54; 27 10;[1oe3]  76 55(x5)
M = [M; 112 35; 118 84; 0 p.fake_sw_b; 118 85;     wait_4];% 70 23; 76 54; 00 ??;        76 55(x5)
M = [M; 112 20; 118 84; idelay_b; 118 85;          wait_4];% 70 14; 76 54; 03 de [a=30, b=30, clk=0]; 76 55(x5)
M = [M; 112 0];                                    %init     70 00

% bit stuffing 
M = flip(M,2);
M = [M zeros(size(M))];
M = M'; %because data are read by column

% save in .bin file
f = fopen('param_tx.bin', 'w');
fwrite(f, M, 'uint8');
fclose(f);

% write bin file to xillybus device file 
command = 'cat param_tx.bin > \\.\xillybus_write_32';
status = system(command); %return 0 if command is succesfull
%     [status,cmdout] = system(command)
% if status==0; disp('Parameters sent to fpga'); else; disp('Error: parameters not sent to fpga') ; end
if status==1; disp('Error: parameters not sent to fpga') ; end
end
