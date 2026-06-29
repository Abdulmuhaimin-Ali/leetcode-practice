/* brute force solution:
for every element loop until sum is equal to or bigger then target

note: this solution exceeds limit but it works for small inputs
*/


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_size_sub = INT_MAX;
        bool found = false;

        for(int i = 0; i < nums.size(); i++){
            int sum = 0; 
            for(int j = i; j < nums.size(); j++){
 
                sum += nums[j];
                if (sum >= target){
                    min_size_sub = min(min_size_sub, (j - i) + 1);
                    found = true;
                    break;
                }
            }
        }

        return found ? min_size_sub : 0;
    }
};

// [2,3,1*,2,4,3] target = 7
// sum = 4
// i = 1;
// j = 2;
// min_size_sub = 4 // break



// Sliding window solution
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_size_sub = INT_MAX;
        int window_start = 0;
        bool found = false;

        int window_sum = 0;
        for(int i = 0; i < nums.size(); i++){
   
            window_sum += nums[i];
            cout << "w_sum: " << window_sum << endl;
            // if target reached slide
            while(window_sum >= target){
                found = true;

                min_size_sub = min(min_size_sub, (i - window_start) + 1);

                window_sum -= nums[window_start];
                window_start++;
            }
        }

        return found ? min_size_sub : 0;
    }
};
