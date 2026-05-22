function SetAttenuationJDSHA9(HA9,Attenuation,Offset)
%Attenuation and Offset values in dB
if ~exist('HA9','var')
    fprintf('missing device name\n')
    return;
elseif ~exist('Attenuation','var')
    fprintf('missing attenuation\n')
    return;
end
if ~exist('Offset','var')
    Offset=0;%dB
end
fprintf(HA9, [':INP:OFFS ' num2str(Offset) ';:INP:ATT ' num2str(Attenuation)]);
pause(1);
end