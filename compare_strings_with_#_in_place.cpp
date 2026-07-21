class Solution {
public:
    // handles decrementing our pointers
    int get_next_index(string s, int index){
        int backspace_count = 0;
        while(index >= 0){
            if(s[index] == '#'){
                backspace_count++;
            }
            else if(backspace_count > 0){
                backspace_count--;
            }
            else{
                break;
            }
            index--;
        }
        return index;
    } 

    bool backspaceCompare(string s, string t) {

        int s_ptr = s.length() - 1;
        int t_ptr = t.length() - 1;

        while (s_ptr >= 0 && t_ptr >= 0){
            int i = get_next_index(s, s_ptr);
            int j = get_next_index(t, t_ptr);


            if(j < 0 && i < 0){
                return true;
            }

            if(j < 0 || i < 0){
                return false;
            }

            if(s[i] != t[j]){
                return false;
            }
            s_ptr = i - 1;
            t_ptr = j - 1;
        }
        return true;
    }
};