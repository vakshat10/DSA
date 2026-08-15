class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorr = 0;
        int l = 0;

        for(int i = 0; i < nums.size();i++){
            xorr = xorr^nums[i];
            if(nums[i] != 0){
                l = 1;
            }
        }

        if(l== 0){
            return 0;
        }
        if(xorr == 0){
            return nums.size()-1;
        }
        else{
            return nums.size();
        }
    }
};