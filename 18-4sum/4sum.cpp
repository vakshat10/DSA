class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {  // // Fix first element, then use j, k, l for the remaining 3
            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            for(int j=i+1; j<n-2; j++){
             //   skip duplicate second elements
                if (j>i+1 && nums[j] == nums[j-1]){
                    continue;
                }

            int k = j+1;
            int l= n-1;

            while (k < l) {
                long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];

                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});

                    k++;
                    l--;

                    // Skip duplicate k values
                    while (k < l && nums[k] == nums[k - 1])
                        k++;

                    // Skip duplicate l values
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum < target) {
                    k++;
                }
                else {
                    l--;
                }
            }
        }
        }

        return ans;
    }
};