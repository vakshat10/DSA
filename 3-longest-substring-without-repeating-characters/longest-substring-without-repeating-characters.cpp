class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0;
        int maxLen = 0;
        int hash[256];

        // Initialize all characters as not seen
        for (int i = 0; i < 256; i++) {
            hash[i] = -1;
        }

        while (right < n) {

            // If character was seen inside the hash 
            if (hash[s[right]] != -1) {

                if (hash[s[right]] >= left) {   // character inside current window
                    left = hash[s[right]] + 1;
                }
            }

            // Calculate the current window length
            int len = right - left + 1;
            maxLen = max(maxLen, len);

            // Store the latest index of this character
            hash[s[right]] = right; 

            right++;
        }

        return maxLen;
    }
};