function [ obj ] = hameg_init( port )
    % Initialise HAMEG Power Source

    obj = serial(port);                                  % create device object
    fopen(obj);                                          % connect to the device
    fprintf('Power Source: %s.\n', query(obj, '*idn?')); % read device ID

end
