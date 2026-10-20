class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < n; i++) {

            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && asteroids[i] < 0) {

                if (st.top() > -asteroids[i]) {

                    destroyed = true; // no need to add next element
                    break;

                }

                else if (st.top() < -asteroids[i]) {
                    st.pop(); // remove top element

                }

                else { // top == asteroids[i]
                    st.pop();
                    destroyed = true;
                    break;
                }
            }

            if (destroyed == false) {
                st.push(asteroids[i]);
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};