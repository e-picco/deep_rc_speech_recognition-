function [ EI, f_mean, f_sd ] = expected_improvement( x_grid, gp_model, f_best )
%EXPECTED_IMPROVEMENT Compute expected improvement of model GP_MODEL over
%grid X_GRID, compared to the optimal solution F_BEST
%   Refs: https://thuijskens.github.io/2016/12/29/bayesian-optimisation/,
%   and Gelbart2014Bayesian (arXiv)

% Written by P. Antonik, Sep 2018

%NOTE1: this stage was done in Matlab's code. Yet to understand it.
%Somehow, it converts the standard deviation of the GP model into SD of
%F?

margin = 0;

[f_mean, y_sd, ~] = predict(gp_model, x_grid);          % evaluate GP model over the grid
f_sd  = sqrt(max(0, y_sd.^2 - gp_model.Sigma.^2));      % NOTE1. Want SD of F, not Y. Need max to avoid complex sqrt.
z_x   = (f_best - margin - f_mean)./f_sd;               % evaluate z(x) function over x_grid
cdf_z = normcdf(z_x, 0, 1);                             % compute Cumul. Distrib. Funct. of z over x_grid

EI = f_sd.*(z_x.*cdf_z + normpdf(z_x, 0, 1));           % compute EI according to formulas in Refs

end


