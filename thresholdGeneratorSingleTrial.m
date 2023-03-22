function scores = thresholdGeneratorSingleTrial(W, Ssynth, Wq, i)
    fprintf("thresholdGeneratorSingleTrial - trial %f\n", i)
    % 'all' call finds max across all temporal correlation sets and frequency bins just like we do in the dectection code.
    scores = max(abs(W'*Ssynth(:,:,i)).^2 * Wq, [], 'all'); 
