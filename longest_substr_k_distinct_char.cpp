// longest-substring-with-at-most-k-distinct-characters

// Another problem behind a paywall somebody gift me premium

#include <bits/stdc++.h>
#include <climits>
using namespace std;

int longest_substr_k_distinct(string s, int k){

    int longest_substr = -INT_MAX;
    unordered_map<char, int> dist_char_count;

    int window_start = 0;

    for(int i = 0; i < s.length(); i++){
        dist_char_count[s[i]]++;
        
        while(dist_char_count.size() > k){
            dist_char_count[s[window_start]]--;
            if(dist_char_count[s[window_start]] == 0){
                dist_char_count.erase(s[window_start]);
            }
            window_start++;
        }

        longest_substr = max(longest_substr, i - window_start + 1);
    }
    return longest_substr;
}

int main() {
	int a, b, c; 
    a = longest_substr_k_distinct("araaci", 2);
    b = longest_substr_k_distinct("araaci", 1);
    c = longest_substr_k_distinct("cbbebi", 3);

    cout << a << "\n" << b << "\n" << c << "\n" << endl;
}



/*
longestSubstringWithKdistinct("araaci", 2)//4, The longest substring with no more than
longestSubstringWithKdistinct("araaci", 1)//2, The longest substring with no more than
longestSubstringWithKdistinct("cbbebi", 3)//5, The longest substrings with no more tha
*/