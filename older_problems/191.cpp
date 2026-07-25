class Solution {
    public:
        int hammingWeight(int n) {
            int count = 0;
            while(n > 0){
                // mod to find current digit
                if(n%2 == 1){count++;}
                // move left a digit
                n = n / 2;
            }
            return count;
        }
    };