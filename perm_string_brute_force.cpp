class Solution {
public:

    void map_to_string(unordered_map<char, int> char_freq){
        for(auto pair : char_freq){
            cout << pair.first << " : " << pair.second << endl;
        }
    }
    bool checkInclusion(string s1, string s2) {
        
        // int is_match = 0;
        // int window_start = 0;
        // unordered_map<char, int> s1_map;

        // for(int i = 0; i < s1.length(); i++){
        //     s1_map[s1[i]]++;
        // }
        
        // // try to find a window left - right that has is_match = s1.length
        // for(int w_end = 0; w_end < s2.length(); w_end++){
        //     if(s1_map.contains(s2[w_end])){
        //         // decrement s1_map
        //         s1_map[s2[w_end]]--;

        //         if(s1_map[s2[w_end]] == 0){
        //             is_match++;
        //         }
        //     }


        //     if(is_match == s1_map.size()) return true;

        //     // if we reached size of pattern time to slide window
        //     if(w_end - window_start + 1 == s1.length()){
        //         char temp_char = s2[window_start];
        //         if(s1_map.contains(temp_char)){
        //             if(s1_map[temp_char] == 0){
        //                 is_match--;
        //             }
        //             s1_map[temp_char]++; // give count back to s1 map
        //         }
        //         window_start++; 
        //     }
        // }

        // brute force solution
        int n = s1.length();
        int m = s2.length();
        sort(s1.begin(), s1.end());

        for(int i = 0; i <= m - n; i++)
        {


            string window = s2.substr(i, n);
            sort(window.begin(), window.end());

            cout << "window: " << window << "\n String 1: " << s1 << endl;
            if(window == s1) return true;
        }



        return false;
    }
};