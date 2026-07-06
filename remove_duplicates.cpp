class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int itr = 1;
        int next_distinct_pos = 1;

        while(itr < nums.size()){
            if(nums[next_distinct_pos - 1] != nums[itr]){
                nums[next_distinct_pos] = nums[itr];
                 next_distinct_pos++;
            }
            itr++;
        }

        return next_distinct_pos;
    }
};