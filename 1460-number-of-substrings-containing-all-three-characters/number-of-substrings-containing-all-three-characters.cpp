class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int last[3] = {-1, -1, -1}; // Last indices of a, b, c
        int ans = 0;

        for (int i = 0; i < n; i++) {

            // Update the last seen index of the current character
            if (s[i] == 'a') {
                last[0] = i;
            }
            else if (s[i] == 'b') {
                last[1] = i;
            }
            else {
                last[2] = i;
            }

            // Minimum last-seen index determines valid starting positions
            int mini = min(min(last[0], last[1]), last[2]);

            // Count valid substrings ending at index i
            if(mini!= -1){
            ans += mini + 1;
            }
        }

        return ans;
    }
};