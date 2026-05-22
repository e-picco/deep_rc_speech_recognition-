function [] = reset_p_0(p)

wait_4= repmat([118 85],4,1); %wait

M = [112 0]; %init                               70 00   
M = [M; 112 1];                                % 70 01
M = [M; 112 21; 118 84; [0 0]; 118 85; wait_4];% 70 15; 76 54; 00 1D; 76 55(x5)
M = [M; 112 32; 118 84; [0 0]; 118 85; wait_4];% 70 20; 76 54; 00 1F; 76 55(x5)
M = [M; 112 27; 118 84; [0 0]; 118 85; wait_4];% 70 1B; 76 54; 00 32; 76 55(x5)
M = [M; 112 26; 118 84; [0 0]; 118 85; wait_4];% 70 1A; 76 54; 00 05; 76 55(x5)
M = [M; 112 28; 118 84; [0 0]; 118 85; wait_4];% 70 1C; 76 54; 00 05; 76 55(x5)
M = [M; 112 22; 118 84; [0 0]; 118 85; wait_4];% 70 16; 76 54; 01 F4; 76 55 (N=500=[1 244])
M = [M; 112 29; 118 84; [0 0] ;118 85; wait_4];% 70 1d; 76 54; 00 00; 76 55 [0 0]
M = [M; 112 33; 118 84; [0 0];118 85;  wait_4];% 70 21; 76 54; 00 24; 76 55 [0 36] 
M = [M; 112 36; 118 84; [0 0]; 118 85; wait_4];% 70 24; 76 54; ?? ??; 76 55(x5)
M = [M; 112 35; 118 84; [0 0]; 118 85; wait_4];% 70 23; 76 54; 00 ??; 76 55(x5)
M = [M; 112 20; 118 84; [0 0]; 118 85; wait_4];% 70 14; 76 54; 28 00; 76 55(x5)
M = [M; 112 0]; %init                            70 00

% bit stuffing 
M = flip(M,2);
M = [M zeros(size(M))];
M = M'; %because data are read by column

% save in .bin file
f = fopen('param0_tx.bin', 'w');
fwrite(f, M, 'uint8');
fclose(f);

% write bin file to xillybus device file 
command = 'cat param0_tx.bin > \\.\xillybus_write_32';
status = system(command); %return 0 if command is succesfull
%     [status,cmdout] = system(command)
if status==0; disp('Parameters 0 sent to fpga'); else; disp('Error: parameters 0 not sent to fpga') ; end
end
