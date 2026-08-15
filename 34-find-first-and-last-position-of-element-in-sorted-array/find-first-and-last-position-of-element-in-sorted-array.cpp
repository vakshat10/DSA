class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        // Target does not exist
        if(lb == ub) {
            return {-1, -1};
        }

        // First occurrence = lb
        // Last occurrence = ub - 1

        else{
             return {lb, ub - 1};
        }
    }
};