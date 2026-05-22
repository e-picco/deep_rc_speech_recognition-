function SetOffJDSHA9(HA9)
if ~exist('HA9','var')
    fprintf('missing device name\n')
    return;
end
fprintf(HA9, 'OUTP OFF ');
end