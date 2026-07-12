class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // so basically we keep a pointer that keeps track of how large our array is

        int next_val = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[next_val] = nums[i];
                next_val++;
            }
        }
    
        return next_val;
    }
};