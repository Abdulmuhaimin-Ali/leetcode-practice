/* Longest Repeating Character Replacement */



// keep track of the biggest frequency your answer is max_freq + k;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest_substr = -INT_MAX;
        int max_repeat_letter_count = 0;
        unordered_map<char, int> letter_freq;
        int window_start = 0;

        for(int i = 0; i < s.length(); i++){
            letter_freq[s[i]]++;
            
            max_repeat_letter_count = max(max_repeat_letter_count,letter_freq[s[i]]);

            if((i - window_start + 1) - max_repeat_letter_count > k){
                letter_freq[s[window_start]]--;
                window_start++;
            }

            longest_substr = max(longest_substr, i - window_start + 1);
            
        }
        return longest_substr;
    }
};
