class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int l = 0;
            int r = 0;
            unordered_set<char> letters;
            int maxLength = 0;
    
            while(r < s.length()){
    
                if(letters.find(s[r]) == letters.end()){
                    letters.insert(s[r]);
                    maxLength = max(maxLength, r - l + 1);
                    r++;
                }else{
                    letters.erase(s[l]);
                    l++;
                }
    
            }
            return maxLength;
        }
    };