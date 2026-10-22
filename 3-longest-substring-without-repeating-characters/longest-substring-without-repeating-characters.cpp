class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int maxLen = 0;
        int hash[256];

        // Initialize all characters as not seen
        for (int i = 0; i < 256; i++) {
            hash[i] = -1;
        }

        while (r < n) {

            // If character was seen inside the hash 
            if (hash[s[r]] != -1) {

                if (hash[s[r]] >= l) {   // character inside current window
                    l = hash[s[r]] + 1;
                }
            }

            // Calculate the current window length
            int len = r - l + 1;
            maxLen = max(maxLen, len);

            // Store the latest index of this character
            hash[s[r]] = r; 

            r++;
        }

        return maxLen;
    }
};