class Solution {
    public:
        vector<int> countBits(int n) {
            // return an array which contains the hamming weight of each number from 0 to i
            vector<int> hammingWeights;
            for(int i = 0; i <= n; i++){
                hammingWeights.push_back(findHammingWeight(i));
            }
        return hammingWeights;
        }
    
        int findHammingWeight(int n){
            int res = 0;
            while(n > 0){
                res++;
                //remove the left most 1 in the binary representation
                n &= n - 1;
            }
            return res;
        }
    };
    