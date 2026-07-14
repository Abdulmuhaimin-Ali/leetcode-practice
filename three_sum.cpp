class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // since we don't want duplicates we'll want to skip every value that has the possibility to generate an identical answer

       vector<vector<int>> res;
       sort(nums.begin(), nums.end());

       for(int start = 0; start < nums.size(); start++){
        
           // skip duplicates
           if(start > 0 && nums[start] == nums[start-1]){
            continue;
           }
           int start_subarr = start+1;
           int end_subarr = nums.size() - 1;

           // two sum problem
           // if below zero increment j 
           // else decrement k 

           while(start_subarr < end_subarr){ 
                int sum = nums[start] + nums[start_subarr] + nums[end_subarr];
                if(sum == 0){
                   res.push_back({nums[start], nums[start_subarr], nums[end_subarr]});
                    start_subarr++;
                    end_subarr--;
                    
                    while(start_subarr < end_subarr && nums[start_subarr] == nums[start_subarr-1] ){
                        start_subarr++;
                    }
                    while(start_subarr < end_subarr && nums[end_subarr] == nums[end_subarr+1]){
                        end_subarr--;
                    }
                }
                else if(sum > 0){
                    end_subarr--;;
                } else{
                    start_subarr++;
                }
           }
       } 
           return res;
    };
};