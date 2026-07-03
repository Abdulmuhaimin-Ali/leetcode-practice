class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        
        int window_start = 0;
        int isMatch = 0; 
        unordered_map<char, int> s1_char_freq;
        unordered_map<char, int> window_char_freq;

        bool isPerm = false;
        
        for(int i = 0; i < s1.length(); i++){
            s1_char_freq[s1[i]]++;
        }

        // check windows with size = s1.length 
        // match window_char_freq freq with s1_char_freq

        cout << "Size of Pattern Map: " << s1_char_freq.size() << endl;
        for(int i = 0; i < s2.length(); i++){
            if(s1_char_freq.find(s2[i]) != s1_char_freq.end()){
                s1_char_freq[s2[i]]--;
                cout << "Char " << s2[i] << " count: " << s1_char_freq[s2[i]] << endl;
                if(s1_char_freq[s2[i]] == 0){
                    isMatch++;
                }
            }
            cout << "Matches: " << isMatch << endl;
            if(isMatch == s1_char_freq.size()){
                isPerm = true;
            }

            if(i - window_start + 1 >= s1.length()){
                
                // we don't want to add or check random keys
                if(s1_char_freq.find(s2[window_start]) != s1_char_freq.end()){
                    if(s1_char_freq[s2[window_start]] == 0){
                        isMatch--;
                    }
                    s1_char_freq[s2[window_start]]++;
                }
                window_start++;
            }
        }
        return isPerm; 
    }
};

// Time Complexity O(n)