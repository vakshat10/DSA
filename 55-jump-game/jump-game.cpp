class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return true;
        }
        int maxi = 0;
        for(int i = 0;i<n;i++){

            int reach = i + nums[i];
            maxi = max(maxi,reach);

            if(maxi >= n-1) return true;

            if(nums[i] == 0 && reach == maxi){
                return false;

            }



        }
        return true;
        
    }
};