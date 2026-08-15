class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int ub = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        
        if(ub-lb == 0){   // target does not exist
            return {-1,-1};
        }
        else if(ub == lb+1){  // target appears single time
            return {lb,lb};
        }
        else{                   // target appears multiple time
            return {lb,ub-1};
        }
    }
};