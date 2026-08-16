class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int low = 0;
        int high = n-1;
        int mini = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            mini = min(mini,nums[mid]);
            if(nums[mid]<=nums[high]){
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return mini;
        
    }
};