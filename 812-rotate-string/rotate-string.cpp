class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();

        // Both strings must have the same length
        if(s.size() != goal.size())
            return false;

        // Try all possible rotations
        for(int j = 1; j <= n; j++) {

            // Create string of size n to store the rotated string
            string ans(n, ' ');

            // Move the first character to the end
            ans[n - 1] = s[0];

            // Shift all remaining characters one position to the left
            for(int i = 0; i < n - 1; i++) {
                ans[i] = s[i + 1];
            }

            // Update s with the rotated string
            s = ans;

            // Check if current rotation matches goal
            if(ans == goal) {
                return true;
            }
        }

        return false;
    }
};