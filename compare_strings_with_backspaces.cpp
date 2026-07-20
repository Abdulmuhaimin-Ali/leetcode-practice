class Solution {
public:

    string process_string(string s){
        stack<char> letters_s;

        string result = "";
        for(char c: s){
            if(c == '#'){
                if(!letters_s.empty()){
                    letters_s.pop();
                }
                else {
                    continue;
                }
            }
            else{
                letters_s.push(c);
            }
        }

        while(!letters_s.empty()){
            result += letters_s.top();
            letters_s.pop();
        }

        return result;
    }

    bool backspaceCompare(string s, string t) {
        
        s = process_string(s);
        t = process_string(t);

        return s == t ? true : false;
    }
};