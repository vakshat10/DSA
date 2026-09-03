class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";

        // Handle empty vector
        if(n == 0)
            return ans;

        // If only one string, it is the prefix
        if(n == 1)
            return strs[0];

        int num = INT_MAX; // Minimum common prefix length

        // Compare every pair of adjacent strings
        for(int i = 0; i < n - 1; i++) {
            int count = 0;

            // Compare characters at the same index
            for(int j = 0; j < strs[i].size() && j < strs[i + 1].size(); j++) {
                if(strs[i][j] == strs[i + 1][j])
                    count++;
                else
                    break;
            }

            // Keep the smallest common prefix length
            num = min(num, count);
        }

        // Build the final answer using the first string
        for(int i = 0; i < num; i++) {
            ans += strs[0][i];
        }

        return ans;
    }
};