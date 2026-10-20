class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < n; i++) {

            // Assume the current asteroid survives
            bool destroyed = false;

            // Collision occurs only when the stack's top is moving
            // right (positive) and the current asteroid is moving left (negative)
            while (!st.empty() && st.top() > 0 && asteroids[i] < 0) {

                // Stack's top asteroid is larger, so current asteroid is destroyed
                if (st.top() > -asteroids[i]) {
                    destroyed = true;
                    break;
                }

                // Current asteroid is larger, so destroy the stack's top
                // Continue checking for more possible collisions
                else if (st.top() < -asteroids[i]) {
                    st.pop();
                }

                // Both asteroids have equal size, so both are destroyed
                else {
                    st.pop();
                    destroyed = true;
                    break;
                }
            }

            // If the current asteroid survived all collisions, push it onto the stack
            if (destroyed == false) {
                st.push(asteroids[i]);
            }
        }

        // Transfer remaining asteroids from the stack to the answer vector
        // Note: Stack gives elements in reverse order
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // Restore the original left-to-right order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};