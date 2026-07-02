class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int window_start = 0;
        int max_ones_count = 0;
        int max_length = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                max_ones_count++;
            }

            if(i - window_start + 1 - max_ones_count > k){
                if(nums[window_start] == 1){
                    max_ones_count--;
                }
                window_start++;
            }

            max_length = max(max_length, i - window_start + 1);
        }

        return max_length;
    }
};