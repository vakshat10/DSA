class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        stack<int> st;
        int i = 0;

        while(i<n) {

            bool destroyed = false;

            while (!st.empty() && st.top() >= 0 && asteroids[i] < 0) {

                if (-asteroids[i] > st.top()) {
                    st.pop();
                }

                else if(-asteroids[i] == st.top()){
                    st.pop();
                    destroyed = true;
                    break;
                   
                }

                else{
                    destroyed = true;
                    break;
                    
                }
            }

            if (destroyed == false) {
                st.push(asteroids[i]);
            }

            i++;
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};