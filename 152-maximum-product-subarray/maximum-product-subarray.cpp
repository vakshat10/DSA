class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        // Prefix and suffix products
        int prefix = 1;
        int suffix = 1;

        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {

            // Reset after zero
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;

            prefix = prefix* nums[i];
            suffix = suffix* nums[(n-1)-i];

            // Maximum from both directions
            ans = max(ans, max(prefix, suffix));
        }

        return ans;
    }
};