class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            int left = 1;
            int right = *max_element(piles.begin(), piles.end());
            int res = right; 
    
            while(left <= right){
                int midP = (left+right)/2;
    
                long long totalHours = 0;
                for(int pile: piles){
                    totalHours += ceil((double)(pile) / midP);
                }
    
                if(totalHours <= h){
                    res = midP;
                    right = midP -1 ;
                }  else{
                    left = midP + 1;
                }
            }
            return res;
    
        }
    };