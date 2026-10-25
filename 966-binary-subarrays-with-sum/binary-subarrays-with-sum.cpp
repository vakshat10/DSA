class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mpp;  // prefix sum -> frequency

        mpp[0] = 1;  // Empty prefix
        int sum = 0, count = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // Find previous prefix sums that make subarray sum = goal
            if (mpp.find(sum - goal) != mpp.end()) {
                count += mpp[sum - goal];
            }

            // Store the current prefix sum
            mpp[sum]++;
        }

        return count;
        
    }
};