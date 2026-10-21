class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;

        int left = 0;
        int count = 0, ans = 0;

        for (int i = 0; i < n; i++) {

            // If duplicate exists, move left past its previous index
            if (mpp.find(s[i]) != mpp.end()) {
                left = max(left, mpp[s[i]] + 1);
            }

            // Store the latest index of the character
            mpp[s[i]] = i;

            // Calculate current window length and update maximum
            count = i - left + 1;
            ans = max(ans, count);
        }

        return ans;
    }
};