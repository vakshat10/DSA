class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int n = s.size();
        int depth = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                if(depth > 0) {
                    ans = ans + s[i];
                }
                depth++;
            }
            else if(s[i] == ')') {
                depth--;
                if(depth > 0) {
                    ans = ans + s[i];
                }
            }
        }

        return ans;
    }
};