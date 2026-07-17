class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==1 || k==0){
            return 0;
        }
        int total_subarray_count = 0;
        int total_product = 1;

        int w_start = 0;

        for(int w_end = 0; w_end < nums.size(); w_end++){
            total_product*=nums[w_end];

            while(total_product >= k && w_start < nums.size()){
                total_product /= nums[w_start];
                w_start++;
            }

            total_subarray_count += w_end - w_start + 1;
        }

        return total_subarray_count;
    }
};