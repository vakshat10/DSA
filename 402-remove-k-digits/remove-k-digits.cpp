class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.size();
        
        stack<char> st;
        string ans;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }

            if(st.size() == 1 && st.top() == '0'){  // remove leading zeroes eg "10200" k = 1  -> "0200" == "200"
                st.pop();
            }

            st.push(num[i]);
        }

        while(!st.empty() && k>0){
            st.pop();
            k--;
        }

        

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        } 

        

        reverse(ans.begin(), ans.end());

        if(ans.empty()){
            return "0";
        }

        

        return ans;
    }
};