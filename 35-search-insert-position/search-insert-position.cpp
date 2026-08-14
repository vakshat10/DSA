class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n ; 

        while(low<=high){
            int mid = (low+high)/2;

            // may be an ans
            if(nums[mid]>= target){
                ans = mid; 
                // look for more small index on left
                high = mid-1;
            }
            else{
                low = mid+1;  // look for right
            }
        }
        return ans;

        
    }
};