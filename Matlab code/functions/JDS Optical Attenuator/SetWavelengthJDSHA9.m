function SetWavelengthJDSHA9(HA9,Wavelength)
%Wavelength in nm
if ~exist('HA9','var')
    fprintf('missing device name\n')
    return;
elseif ~exist('Wavelength','var')
    fprintf('missing wavelength\n')
    return;
end

fprintf(HA9, [':INP:WAV ' num2str(Wavelength) ' nm']);
end