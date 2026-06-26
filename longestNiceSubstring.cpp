class Solution {
public:
    string longestNiceSubstring(string s) {
        
        int n = s.length();

        if(n < 2){
            return "";
        }

        for(int i = 0; i < n; i++){
            char c = s[i];

            bool hasUpper = false, hasLower = false;
            for( char x : s){
                if(tolower(c) == tolower(x)){
                    if(isupper(x)) hasUpper = true;
                    else hasLower = true;
                }
            }
            
            // if one missing then good point to split
            if(!hasUpper || !hasLower){

                string left = longestNiceSubstring(s.substr(0, i));
                string right = longestNiceSubstring(s.substr(i + 1));

                return left.length() >= right.length() ? left : right;
            }
        }

        // if all letters have lower and upper return s
        return s;
    }
};

