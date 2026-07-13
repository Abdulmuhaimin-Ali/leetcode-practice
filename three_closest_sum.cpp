class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        int best_sum = 0;
        int small_dist = INT_MAX;

        for(int start = 0; start < nums.size(); start++){

            int start_subarr = start + 1;
            int end_subarr = nums.size() - 1;

            // two pointer to get closer to target
            while(start_subarr < end_subarr){
                int sum = nums[start] + nums[start_subarr] + nums[end_subarr];
                int target_diff = target - sum;

                if(abs(target_diff) < small_dist){
                    small_dist = abs(target_diff);
                    best_sum = (nums[start] + nums[start_subarr] + nums[end_subarr]);
                }

                if(sum == target){
                    return sum;
                }
                else if(sum > target){
                    end_subarr--;
                }else {
                    start_subarr++;
                }
            }
        }
        return best_sum;
    }
};

// [-1,2,1,-4]

