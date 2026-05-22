function [TotalAtt] = GetAttenuationJDSHA9(HA9)
%TotalAtt in dB
if ~exist('HA9','var')
    fprintf('missing device name\n')
    return;
end

Attenuation=query(HA9,':INP:ATT?');
Offset=query(HA9,':INP:OFFS?');
TotalAtt=str2double(Attenuation)+str2double(Offset);

end