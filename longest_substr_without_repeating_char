// Author: Muhaimin Ali
// Brute Force solution

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestSubstring = 0;

        for(int i = 0; i < s.length(); i++){
            unordered_map<char, int> letterMap;
            for(int j = i; j < s.length(); j++){

                if(letterMap[s[j]] == 1) break;
                letterMap[s[j]] = 1;
                longestSubstring = max(longestSubstring, j - i + 1);
            }
        }

        return longestSubstring;
    }
};

// Time Complexity O(n^2) where n is the length of the string


// Improved sliding window approach

// Sliding Window Method

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int longest_substr = 0;

        unordered_map<char, int> seen;

        int left = 0;
        for(int i = 0; i < s.length(); i++){
            seen[s[i]]++;

            while(seen[s[i]] > 1 && left < s.length()){
                seen[s[left]]--;
                left++;
            }
            longest_substr = max(longest_substr, i - left + 1);
        }

        return longest_substr;
    }
};

// Time Complexity is O(n) where n is the length of the string
// Space Complexity is O(min(n, m)) where n is the length of the string and m is the size of the character set

// Notes
