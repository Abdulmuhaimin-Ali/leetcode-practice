class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double max_average = -DBL_MAX;
        double window_sum = 0;
        int left = 0;

        int window_size = 0;

        for(int i = 0; i < nums.size(); i++){
            window_sum += nums[i];
            

            while ((i - left + 1) > k && left < nums.size()){
                window_sum -= nums[left];
                left++;
            }

            window_size = i - left + 1;

            if(window_size == k){
                max_average = max(max_average, (window_sum / window_size));
            }
        }

        return max_average;
    }
};

// 1,12,-5,-6,50,3

// sum = 52
// max_ave = 12.75
// left = 1





// // nums = [1,12,-5,-6,50,3], k = 4

// // maxAverage = 0
// // for every element
//     // sum = 0
//     // for k amount of elements after i
    
//     // maxAverage = max(maxAverage, sum / k)
// O(n^2) where n is the length of nums array
// O(1)
// // Sliding window method

// // nums = [1,12,-5,-6,50,3], k = 4
// // window_sum
// // 1,12,-5,-6 
// // 12,-5,-6,50

// // get average form window 

// // keep going until we reach the end. 

// O(n) where n is the length of nums array






