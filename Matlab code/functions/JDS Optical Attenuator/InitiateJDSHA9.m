function HA9=InitiateJDSHA9()
% Find a GPIB object.
% HA9 = instrfind('Type', 'serial', 'Port', 'COM9', 'Tag', '');
HA9 = [];%instrfind('Type', 'visa-gpib', 'RsrcName', 'GPIB0::10::INSTR', 'Tag', '');
% Create the GPIB object if it does not exist
% otherwise use the object that was found.
if isempty(HA9)
%     HA9 = serial('COM9');
    HA9 = visa('AGILENT', 'GPIB0::10::INSTR');
else
    fclose(HA9);
    HA9 = HA9(1);
end

% Connect to instrument object, HA9.
fopen(HA9);

% Communicating with instrument object, HA9.
data = query(HA9, '*idn?');
fprintf('Optical Attenuator: %s\n',data(1:end-1));
clear data;

fprintf(HA9, 'OUTP ON ');

end