function CloseJDSHA9(HA9)
if ~exist('HA9','var')
    fprintf('missing device name\n')
    return;
end
fprintf(HA9, 'OUTP OFF ');
fclose(HA9);
clear HA9;
end