class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, maxLen = 0, maxFreq = 0;
        unordered_map<char, int> mpp;

        for (int right = 0; right < n; right++) {

            mpp[s[right]]++;
            maxFreq = max(maxFreq, mpp[s[right]]);

            int length = right - left + 1;

            // Replacements needed > k: shrink the window
            while (length - maxFreq > k) {
                mpp[s[left]]--;
                left++;

                length = right - left + 1;
            }

            maxLen = max(length, maxLen);
        }

        return maxLen;
    }
};