class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];

            int Rsum = sum - k;

            // Check how many previous prefix sums equal Rsum
            if(mp.find(Rsum) != mp.end()) {
                count = count + mp[Rsum];
            }

            // Store current prefix sum
            mp[sum]++;
        }

        return count;
    }
};