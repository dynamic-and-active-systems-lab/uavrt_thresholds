function [mu, sigma] = thresholdGeneratorPost(scores)
    paramEstsMaxima = evfit(-scores);
    mu              = paramEstsMaxima(1);
    sigma           = paramEstsMaxima(2);
end