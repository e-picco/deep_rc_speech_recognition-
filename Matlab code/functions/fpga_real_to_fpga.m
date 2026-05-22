function [ output_fpga, output_debug ] = fpga_real_to_fpga (array, n_bits)
    % Convert array of N reals to array of 2N bytes to transmit to FPGA
    % Written by Piotr Antonik, Jan 2019
 
    % make sure the input vector is row
    if ~isrow(array)
        array = array';
    end
    
    a = round(array * 2^n_bits);
    output_debug = a;
    
    a(a<0)    = 2^16 + a(a<0) - 1;
    
    bytes = [floor(a/2^8); rem(a, 2^8)]';
    output_fpga = reshape(bytes', 2*length(array), 1)';
end

