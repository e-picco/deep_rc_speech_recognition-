function [inputs, targets ] = gen_chan_data ( n_symbols, seed, amp )
    % Generate inputs and targets for the channel equalisation task
    % Written by Piotr Antonik, Jan 2019

    rng(1);
    systemorder     = 10;
    p1              = 1;
    p2              = 0.036;
    p3              = -0.011;
    d               = 2*randi(4,1,n_symbols+2*systemorder)-(1+4);
    for n=systemorder-2:n_symbols+systemorder-2-1
        % channel memory (linear)
        q = 0.08*d(n+2) - 0.12*d(n+1) + d(n) + 0.18*d(n-1) - 0.1*d(n-2) + ...
            0.091*d(n-3) - 0.05*d(n-4) + 0.04*d(n-5) + 0.03*d(n-6) + 0.01*d(n-7);
        % channel nonlinearity
        inputs(n-7) = p1*q + p2*q^2 + p3*q^3; %#ok<AGROW>
        % create target signal
        targets(n-7) = d(n); %#ok<AGROW>
    end
    
%     inputs=0*inputs;
%     inputs(1)=1;
    inputs  = inputs * amp;
end
