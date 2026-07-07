class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // the reason we are sorting this is becuase we want to utilize our two pointer approach.
        // works like hot and cold allowing us to get closer to our target 
        sort(nums.begin(), nums.end());
        int smallest_diff = INT_MAX;
        int sum_triplets = 0;
        int arr_size = nums.size()

        for(int i = 0; i < arr_size; i++){
            int j = i+1;
            int k = arr_size - 1;

            // potential solutions
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum == target){
                    sum_triplets = sum;
                    break;
                }

                if(su)

                if(sum < target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return sum_triplets;
    }
};