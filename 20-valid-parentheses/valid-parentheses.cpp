class Solution {
public:
    bool isValid(string s) {

        int n = s.size();

        // stack stores opening brackets that are still waiting for their closing bracket
        stack<char> st;

        for(int i = 0; i < n; i++){

            // opening bracket: push it, its closing bracket will come later
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }

            // closing bracket: it must match the most recent unmatched opening bracket
            else{

                // no opening bracket to match with, so invalid
                if (st.empty()) return false;      // eg "]"

                // ')' needs '(' on top of the stack
                if(s[i] == ')' && st.top() == '('){
                    st.pop();   // matched pair, remove the opener
                }

                // '}' needs '{' on top of the stack
                else if(s[i] == '}' && st.top() == '{'){
                    st.pop();
                }

                // ']' needs '[' on top of the stack
                else if(s[i] == ']' && st.top() == '['){
                    st.pop();
                }

                // closing bracket does not match the top opener, so invalid
                else{
                    return false;   // eg "(]"
                }
            }
        }

        // if the stack is empty, every opener found its closer
        // if not, some openers are still unmatched, so invalid
        return st.empty();   // eg "[[" : leftover openers mean invalid
    }
};