function [ ] = hameg_set_volt( obj, channel, voltage )

    fprintf(obj, ['INST:NSEL ' num2str(channel)]);
    fprintf(obj, ['VOLT ' num2str(voltage)]);

end
