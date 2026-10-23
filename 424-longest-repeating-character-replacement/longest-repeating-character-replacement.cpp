class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, maxLen = 0, maxFreq = 0;
        unordered_map<char, int> mpp;

        for (int right = 0; right < n; right++) {

            mpp[s[right]]++;
            maxFreq = max(maxFreq, mpp[s[right]]);

            int length = right - left + 1; // size of current window

            while (length - maxFreq > k) { // no of elements to change

                mpp[s[left]]--;
                left++;

                length = right - left + 1;

                for(auto it: mpp){
                    maxFreq = max(maxFreq,it.second);
                     
                }


            }

            maxLen = max(length,maxLen);
        }
        return maxLen;
    }
};