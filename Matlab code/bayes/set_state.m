%set idle/train state
clear 

M = [112 0]; %init 70 00
% bit stuffing 
M = flip(M,2);
M = [M zeros(size(M))];
M = M'; %because data are read by column

% save in .bin file
f = fopen('state_tx.bin', 'w');
fwrite(f, M, 'uint8');
fclose(f);

% write bin file to xillybus device file 
command = 'cat state_tx.bin > \\.\xillybus_write_32';
status = system(command); %return 0 if command is succesfull
% if status==0; disp('State sent to fpga'); end