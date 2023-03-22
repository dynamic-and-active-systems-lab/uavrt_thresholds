function [mu, sigma] = thresholdGenerator(Fs, t_p, t_ip, t_ipu, t_ipj, K, trials)
    [ W, Ssynth, Wq ] = thresholdGeneratorPre(Fs, t_p, t_ip, t_ipu, t_ipj, K);
    
    if (isempty(W))
        mu      = 0;
        sigma   = 0;
        return;
    end

    scores = zeros(trials, 1);
    for i = 1:trials
        scores(i) = thresholdGeneratorSingleTrial(W, Ssynth, Wq, i);
    end

    [ mu, sigma ] = thresholdGeneratorPost(scores);
end
