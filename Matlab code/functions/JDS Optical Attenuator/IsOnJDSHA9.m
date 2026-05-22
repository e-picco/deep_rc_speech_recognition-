function On=IsOnJDSHA9(HA9)
if ~exist('HA9','var')
    fprintf('missing device name\n')
    return;
end

On=query(HA9, 'OUTP:STAT?');
   
end