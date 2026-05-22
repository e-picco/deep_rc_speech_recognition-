function [ best_WER_train, best_WER_test, best_lambda, best_out_train, best_out_test] = train_eval_rc (p, x, targets, data, train_size)

best_WER_train =1;
best_WER_test=1;
best_lambda = 0;
best_weights=zeros(10,size(x,1)); %10xN
best_out_train=zeros(1,train_size);
best_out_test=zeros(1,500-train_size);

for l_idx=1:length(p.lambdas)
    lambda=p.lambdas(l_idx);

    %split train/test
    x_train = x(:, 1:data.SplitIndexDigitVector(train_size+1)-1);
    target_train = targets(:,1:data.SplitIndexDigitVector(train_size+1)-1);
    x_test = x(:, data.SplitIndexDigitVector(train_size+1):end);
    target_test = targets(:, data.SplitIndexDigitVector(train_size+1):end);

    %train
    R = x_train*x_train' + lambda*eye(size(x_train,1));
    P = x_train * target_train';
    weights = P' * pinv(R);
    out_train=weights*x_train;
    [~,out_train_vector]=max(out_train);
    for i_digit=1:train_size
        out_train_vector_digit(i_digit) = mode(out_train_vector(data.SplitIndexDigitVector(i_digit):data.SplitIndexDigitVector(i_digit+1)-1));
    end
    WER_train = sum( out_train_vector_digit ~= data.SplitVector(3,1:train_size) ) / train_size;

    %test
    out_test=weights*x_test;
    [~,out_test_vector]=max(out_test);
    for i_digit=1:(499-train_size)
        out_test_vector_digit(i_digit) = mode(out_test_vector(data.SplitIndexDigitVector(i_digit+train_size)-size(x_train,2):data.SplitIndexDigitVector(i_digit+train_size+1)-1-size(x_train,2)));
    end
    out_test_vector_digit(500-train_size) = mode(out_test_vector(data.SplitIndexDigitVector(500)-size(x_train,2):end));
    WER_test = sum( out_test_vector_digit ~= data.SplitVector(3,train_size+1:end) ) / (500-train_size);
    
    %find best lambda
    if WER_test<best_WER_test
        best_WER_test=WER_test;
        best_WER_train=WER_train;
        best_weights=weights;
        best_out_train=out_train_vector_digit;
        best_out_test=out_test_vector_digit;
        best_lambda = lambda;
    end
end
end


