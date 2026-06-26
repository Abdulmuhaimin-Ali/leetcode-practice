class Solution {
    public:
        int characterReplacement(string s, int k) {
          unordered_map<char, int> letterFrequency;
          int l = 0;
          int maxF = 0;
          int result = 0;
    
          for(int r = 0; r < s.length(); r++){
            letterFrequency[s[r]]++;
            maxF = max(maxF, letterFrequency[s[r]]);
    
            //sliding window technique; basically if length - maxF > k this means we can't perform enought subsitution to make this substring valid. So we decrement the frequency in our map and update our position. It catches us 
            while((r - l + 1) - maxF > k){
                letterFrequency[s[l]]--;
                l++;
            }
            result = max(result, r - l + 1);
          }
        return result;
        }
    };
    
    