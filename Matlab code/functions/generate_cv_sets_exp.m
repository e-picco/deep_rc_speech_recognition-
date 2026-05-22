function [reservoir_cv, targets_cv, SplitVector_cv, SplitIndexDigitVector_cv]=generate_cv_sets_exp(reservoir, inputs_shuffled, targets_shuffled, data, digit_length);

%here you generate the 10 cv datasets by splitting the reservoir and targets (500 digits) in 10 subsets.
%then, for every cv dataset, you use each one of these to test and the remaining 9 to train.
%the biggest challenge here is to recreate the vector SplitIndexVector with no mistakes. 
%The other vectors are quite simple to create
%I create them individually since I am pretty sure I would do some mistakes with the indexes of SplitIndexVector

data.digit_length=digit_length;

%% cv 1: use 1th (1-50) for testing 
inputs_cv(:,:,1)= [inputs_shuffled(:,data.SplitIndexDigitVector(51):end) inputs_shuffled(:,1:(data.SplitIndexDigitVector(51)-1))];
targets_cv(:,:,1)=[targets_shuffled(:,data.SplitIndexDigitVector(51):end) targets_shuffled(:,1:(data.SplitIndexDigitVector(51)-1))];
reservoir_cv(:,:,1)   =  [reservoir(:,data.SplitIndexDigitVector(51):end)        reservoir(:,1:(data.SplitIndexDigitVector(51)-1))];
SplitVector_cv(:,:,1)=[data.SplitVector(:,51:end) data.SplitVector(:,1:50)];
%shift values of digit_length
digit_length_this_cv=[data.digit_length(:,51:end) data.digit_length(:,1:50)];

%recreate SplitIndexDigitVEctor (1x500x1st) ,  using the new digit_length
SplitIndexDigitVector_cv(1,1,1)=1;
for i=2:500
    SplitIndexDigitVector_cv(1,i,1) = SplitIndexDigitVector_cv(1,i-1,1) + digit_length_this_cv(i-1);  
end


%% cv 2: use 2nd (51-100) for testing 
inputs_cv(:,:,2)=[inputs_shuffled(:,1:(data.SplitIndexDigitVector(51)-1)) inputs_shuffled(:,data.SplitIndexDigitVector(101):end) inputs_shuffled(:,data.SplitIndexDigitVector(51):data.SplitIndexDigitVector(101)-1) ];
targets_cv(:,:,2)=[targets_shuffled(:,1:(data.SplitIndexDigitVector(51)-1)) targets_shuffled(:,data.SplitIndexDigitVector(101):end) targets_shuffled(:,data.SplitIndexDigitVector(51):data.SplitIndexDigitVector(101)-1) ];
reservoir_cv(:,:,2)=[reservoir(:,1:(data.SplitIndexDigitVector(51)-1)) reservoir(:,data.SplitIndexDigitVector(101):end) reservoir(:,data.SplitIndexDigitVector(51):data.SplitIndexDigitVector(101)-1) ];
SplitVector_cv(:,:,2)=[data.SplitVector(:,1:50) data.SplitVector(:,101:end) data.SplitVector(:,51:100)];
%shift values of digit_length
digit_length_this_cv=[data.digit_length(:,1:50) data.digit_length(:,101:end) data.digit_length(:,51:100)];

%recreate SplitIndexDigitVEctor (1x500x10) ,  using the new digit_length
SplitIndexDigitVector_cv(1,1,2)=1;
for i=2:500
    SplitIndexDigitVector_cv(1,i,2) = SplitIndexDigitVector_cv(1,i-1,2) + digit_length_this_cv(i-1);  
end

%% cv 3: use 3rd (101-150) for testing 
inputs_cv(:,:,3)=[inputs_shuffled(:,1:(data.SplitIndexDigitVector(101)-1)) inputs_shuffled(:,data.SplitIndexDigitVector(151):end) inputs_shuffled(:,data.SplitIndexDigitVector(101):data.SplitIndexDigitVector(151)-1) ];
targets_cv(:,:,3)=[targets_shuffled(:,1:(data.SplitIndexDigitVector(101)-1)) targets_shuffled(:,data.SplitIndexDigitVector(151):end) targets_shuffled(:,data.SplitIndexDigitVector(101):data.SplitIndexDigitVector(151)-1) ];
reservoir_cv(:,:,3)=[reservoir(:,1:(data.SplitIndexDigitVector(101)-1)) reservoir(:,data.SplitIndexDigitVector(151):end) reservoir(:,data.SplitIndexDigitVector(101):data.SplitIndexDigitVector(151)-1) ];
SplitVector_cv(:,:,3)=[data.SplitVector(:,1:100) data.SplitVector(:,151:end) data.SplitVector(:,101:150)];
%shift values of digit_length
digit_length_this_cv=[data.digit_length(:,1:100) data.digit_length(:,151:end) data.digit_length(:,101:150)];

%recreate SplitIndexDigitVEctor (1x500x10) ,  using the new digit_length
SplitIndexDigitVector_cv(1,1,3)=1;
for i=2:500
    SplitIndexDigitVector_cv(1,i,3) = SplitIndexDigitVector_cv(1,i-1,3) + digit_length_this_cv(i-1);  
end

%% cv 4: use 4th (151-200) for testing 
inputs_cv(:,:,4)=[inputs_shuffled(:,1:(data.SplitIndexDigitVector(151)-1)) inputs_shuffled(:,data.SplitIndexDigitVector(201):end) inputs_shuffled(:,data.SplitIndexDigitVector(151):data.SplitIndexDigitVector(201)-1) ];
targets_cv(:,:,4)=[targets_shuffled(:,1:(data.SplitIndexDigitVector(151)-1)) targets_shuffled(:,data.SplitIndexDigitVector(201):end) targets_shuffled(:,data.SplitIndexDigitVector(151):data.SplitIndexDigitVector(201)-1) ];
reservoir_cv(:,:,4)=[reservoir(:,1:(data.SplitIndexDigitVector(151)-1)) reservoir(:,data.SplitIndexDigitVector(201):end) reservoir(:,data.SplitIndexDigitVector(151):data.SplitIndexDigitVector(201)-1) ];
SplitVector_cv(:,:,4)=[data.SplitVector(:,1:150) data.SplitVector(:,201:end) data.SplitVector(:,151:200)];
%shift values of digit_length
digit_length_this_cv=[data.digit_length(:,1:150) data.digit_length(:,201:end) data.digit_length(:,151:200)];

%recreate SplitIndexDigitVEctor (1x500x10) ,  using the new digit_length
SplitIndexDigitVector_cv(1,1,4)=1;
for i=2:500
    SplitIndexDigitVector_cv(1,i,4) = SplitIndexDigitVector_cv(1,i-1,4) + digit_length_this_cv(i-1);  
end

%% cv 5: use 5th (201-250) for testing 
inputs_cv(:,:,5)=[inputs_shuffled(:,1:(data.SplitIndexDigitVector(201)-1)) inputs_shuffled(:,data.SplitIndexDigitVector(251):end) inputs_shuffled(:,data.SplitIndexDigitVector(201):data.SplitIndexDigitVector(251)-1) ];
targets_cv(:,:,5)=[targets_shuffled(:,1:(data.SplitIndexDigitVector(201)-1)) targets_shuffled(:,data.SplitIndexDigitVector(251):end) targets_shuffled(:,data.SplitIndexDigitVector(201):data.SplitIndexDigitVector(251)-1) ];
reservoir_cv(:,:,5)=[reservoir(:,1:(data.SplitIndexDigitVector(201)-1)) reservoir(:,data.SplitIndexDigitVector(251):end) reservoir(:,data.SplitIndexDigitVector(201):data.SplitIndexDigitVector(251)-1) ];
SplitVector_cv(:,:,5)=[data.SplitVector(:,1:200) data.SplitVector(:,251:end) data.SplitVector(:,201:250)];
%shift values of digit_length
digit_length_this_cv=[data.digit_length(:,1:200) data.digit_length(:,251:end) data.digit_length(:,201:250)];

%recreate SplitIndexDigitVEctor (1x500x10) ,  using the new digit_length
SplitIndexDigitVector_cv(1,1,5)=1;
for i=2:500
    SplitIndexDigitVector_cv(1,i,5) = SplitIndexDigitVector_cv(1,i-1,5) + digit_length_this_cv(i-1);  
end

%% cv 6: use 6th (251-300) for testing 
inputs_cv(:,:,6)=[inputs_shuffled(:,1:(data.SplitIndexDigitVector(251)-1)) inputs_shuffled(:,data.SplitIndexDigitVector(301):end) inputs_shuffled(:,data.SplitIndexDigitVector(251):data.SplitIndexDigitVector(301)-1) ];
targets_cv(:,:,6)=[targets_shuffled(:,1:(data.SplitIndexDigitVector(251)-1)) targets_shuffled(:,data.SplitIndexDigitVector(301):end) targets_shuffled(:,data.SplitIndexDigitVector(251):data.SplitIndexDigitVector(301)-1) ];
reservoir_cv(:,:,6)=[reservoir(:,1:(data.SplitIndexDigitVector(251)-1)) reservoir(:,data.SplitIndexDigitVector(301):end) reservoir(:,data.SplitIndexDigitVector(251):data.SplitIndexDigitVector(301)-1) ];
SplitVector_cv(:,:,6)=[data.SplitVector(:,1:250) data.SplitVector(:,301:end) data.SplitVector(:,251:300)];
%shift values of digit_length
digit_length_this_cv=[data.digit_length(:,1:250) data.digit_length(:,301:end) data.digit_length(:,251:300)];

%recreate SplitIndexDigitVEctor (1x500x10) ,  using the new digit_length
SplitIndexDigitVector_cv(1,1,6)=1;
for i=2:500
    SplitIndexDigitVector_cv(1,i,6) = SplitIndexDigitVector_cv(1,i-1,6) + digit_length_this_cv(i-1);  
end

%% cv 7: use 7th (301-350) for testing 
inputs_cv(:,:,7)=[inputs_shuffled(:,1:(data.SplitIndexDigitVector(301)-1)) inputs_shuffled(:,data.SplitIndexDigitVector(351):end) inputs_shuffled(:,data.SplitIndexDigitVector(301):data.SplitIndexDigitVector(351)-1) ];
targets_cv(:,:,7)=[targets_shuffled(:,1:(data.SplitIndexDigitVector(301)-1)) targets_shuffled(:,data.SplitIndexDigitVector(351):end) targets_shuffled(:,data.SplitIndexDigitVector(301):data.SplitIndexDigitVector(351)-1) ];
reservoir_cv(:,:,7)=[reservoir(:,1:(data.SplitIndexDigitVector(301)-1)) reservoir(:,data.SplitIndexDigitVector(351):end) reservoir(:,data.SplitIndexDigitVector(301):data.SplitIndexDigitVector(351)-1) ];
SplitVector_cv(:,:,7)=[data.SplitVector(:,1:300) data.SplitVector(:,351:end) data.SplitVector(:,301:350)];
%shift values of digit_length
digit_length_this_cv=[data.digit_length(:,1:300) data.digit_length(:,351:end) data.digit_length(:,301:350)];

%recreate SplitIndexDigitVEctor (1x500x10) ,  using the new digit_length
SplitIndexDigitVector_cv(1,1,7)=1;
for i=2:500
    SplitIndexDigitVector_cv(1,i,7) = SplitIndexDigitVector_cv(1,i-1,7) + digit_length_this_cv(i-1);  
end

%% cv 8: use 8th (351-400) for testing 
inputs_cv(:,:,8)=[inputs_shuffled(:,1:(data.SplitIndexDigitVector(351)-1)) inputs_shuffled(:,data.SplitIndexDigitVector(401):end) inputs_shuffled(:,data.SplitIndexDigitVector(351):data.SplitIndexDigitVector(401)-1) ];
targets_cv(:,:,8)=[targets_shuffled(:,1:(data.SplitIndexDigitVector(351)-1)) targets_shuffled(:,data.SplitIndexDigitVector(401):end) targets_shuffled(:,data.SplitIndexDigitVector(351):data.SplitIndexDigitVector(401)-1) ];
reservoir_cv(:,:,8)=[reservoir(:,1:(data.SplitIndexDigitVector(351)-1)) reservoir(:,data.SplitIndexDigitVector(401):end) reservoir(:,data.SplitIndexDigitVector(351):data.SplitIndexDigitVector(401)-1) ];
SplitVector_cv(:,:,8)=[data.SplitVector(:,1:350) data.SplitVector(:,401:end) data.SplitVector(:,351:400)];
%shift values of digit_length
digit_length_this_cv=[data.digit_length(:,1:350) data.digit_length(:,401:end) data.digit_length(:,351:400)];

%recreate SplitIndexDigitVEctor (1x500x10) ,  using the new digit_length
SplitIndexDigitVector_cv(1,1,8)=1;
for i=2:500
    SplitIndexDigitVector_cv(1,i,8) = SplitIndexDigitVector_cv(1,i-1,8) + digit_length_this_cv(i-1);  
end

%% cv 9: use9th (401-450) for testing 
inputs_cv(:,:,9)=[inputs_shuffled(:,1:(data.SplitIndexDigitVector(401)-1)) inputs_shuffled(:,data.SplitIndexDigitVector(451):end) inputs_shuffled(:,data.SplitIndexDigitVector(401):data.SplitIndexDigitVector(451)-1) ];
targets_cv(:,:,9)=[targets_shuffled(:,1:(data.SplitIndexDigitVector(401)-1)) targets_shuffled(:,data.SplitIndexDigitVector(451):end) targets_shuffled(:,data.SplitIndexDigitVector(401):data.SplitIndexDigitVector(451)-1) ];
reservoir_cv(:,:,9)=[reservoir(:,1:(data.SplitIndexDigitVector(401)-1)) reservoir(:,data.SplitIndexDigitVector(451):end) reservoir(:,data.SplitIndexDigitVector(401):data.SplitIndexDigitVector(451)-1) ];
SplitVector_cv(:,:,9)=[data.SplitVector(:,1:400) data.SplitVector(:,451:end) data.SplitVector(:,401:450)];
%shift values of digit_length
digit_length_this_cv=[data.digit_length(:,1:400) data.digit_length(:,451:end) data.digit_length(:,401:450)];

%recreate SplitIndexDigitVEctor (1x500x10) ,  using the new digit_length
SplitIndexDigitVector_cv(1,1,9)=1;
for i=2:500
    SplitIndexDigitVector_cv(1,i,9) = SplitIndexDigitVector_cv(1,i-1,9) + digit_length_this_cv(i-1);  
end

%% cv 10: use 10th for testing (like in "original" training)
inputs_cv(:,:,10)=inputs_shuffled;
targets_cv(:,:,10)=targets_shuffled;
reservoir_cv(:,:,10)=reservoir;
SplitVector_cv(:,:,10)=data.SplitVector;
SplitIndexDigitVector_cv(:,:,10)=data.SplitIndexDigitVector(1:500);
% SplitIndexDigitVector_cv(1,500,10)=size(reservoir,2)+1; %K+1 (28385 or 34108)
end


% %NOTE: this does not work because there are consecutive digits with same value :(
% %I think it is just easier to recreate the SplitIndexDigitVector rather
% %than shifting all the indixes every time in a different way
% i_vector=2;
% SplitIndexDigitVector_cv(1)=1;
% current_digit=targets_cv(:,1,1);
% for i=2:34107
%     if sum(not(targets_cv(:,i,1) == current_digit)); %if the digit in target_cv is changing
%         SplitIndexDigitVector_cv(i_vector) = i; %you write the starting index of the new digit
%               
%         %debug ~ 
%         [~, digit_debug(i_vector)]=max(current_digit);
%         
%         current_digit = targets_cv(:,i,1); %and you save which one is the new digit
%         i_vector=i_vector+1;
%     end
% end
% SplitIndexDigitVector_cv(:,:,1)=SplitIndexDigitVector_cv;