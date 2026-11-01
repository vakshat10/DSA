class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < n; i++) {

            bool destroyed = false;

            // Check possible collisions
            while (!st.empty() && st.top() > 0 && asteroids[i] < 0) {

                if (st.top() > -asteroids[i]) {
                    destroyed = true;
                    break;  // Current asteroid is destroyed, stop checking
                }

                else if (st.top() < -asteroids[i]) {
                    st.pop();
                }

                else {
                    st.pop();
                    destroyed = true;
                    break;  // Both asteroids are destroyed, stop checking
                }
            }

            // Push if current asteroid survives
            if (destroyed == false) {
                st.push(asteroids[i]);
            }
        }

        // Transfer stack to answer
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // Restore original order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};