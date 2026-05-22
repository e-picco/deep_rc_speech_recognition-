function [Wavelength] = GetWavelengthJDSHA9(HA9)
%output Wavelength in nm
if ~exist('HA9','var')
    fprintf('missing device name\n')
    return;
end

Wavelength=query(HA9,':INP:WAV?');
Wavelength=str2double(Wavelength)*1e9;

end