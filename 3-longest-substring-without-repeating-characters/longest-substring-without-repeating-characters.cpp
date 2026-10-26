class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
        int left = 0, maxLen = 0;

        for (int right = 0; right < n; right++) {

            // If character appeared before, move left forward
            if (mpp.find(s[right]) != mpp.end()) {
                left = max(left, mpp[s[right]] + 1);
            }

            // Store the latest index of the character
            mpp[s[right]] = right;

            // Update maximum window length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};