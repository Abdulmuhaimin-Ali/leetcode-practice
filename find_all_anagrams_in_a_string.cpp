class Solution {
public:

    void print_map(unordered_map<char, int> map){
        cout << "\nMap:\n";
        for(auto pair : map){
            cout << pair.first << " : " << pair.second << "\n";
        }
        cout << "\n";
    }

    bool isIn(char key, unordered_map<char, int> map){
        return map.find(key) != map.end()? true : false;
    }

    vector<int> findAnagrams(string s, string p) {
        int isMatch = 0;
        int window_start = 0;
        vector<int> num_of_perms;

        unordered_map<char, int> p_letter_freq;

        for(int i = 0; i < p.length(); i++){
            p_letter_freq[p[i]]++;
        }

        cout << "Size of our map: " << p_letter_freq.size() << endl;
        for(int i = 0; i < s.length(); i++){
            int window_size = (i - window_start + 1);

            if(isIn(s[i], p_letter_freq)){
                p_letter_freq[s[i]]--;

                if(p_letter_freq[s[i]] == 0){
                    isMatch++;
                }
            }

            if(isMatch == p_letter_freq.size()){
                num_of_perms.push_back(window_start);
            }

            // cha cha slide
            if(window_size >= p.length()){
                cout << " modifying map " << endl;
                if(p_letter_freq.find(s[window_start]) != p_letter_freq.end()){
                    if(p_letter_freq[s[window_start]] == 0){
                        isMatch--;
                    }
                    p_letter_freq[s[window_start]]++;
                }
                window_start++;
            }

        }
        return num_of_perms;
    }
};