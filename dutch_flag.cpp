class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> num_freq;

        for(int num: nums){
            num_freq[num]++;
        }

    
        int color = 0; // start
        int i = 0;
        while(color < 3){

            while(num_freq[color] != 0 && i < nums.size()){
                nums[i] = color;
                num_freq[color]--;
                i++;
            }
            color++; // next color
        }

    }
};