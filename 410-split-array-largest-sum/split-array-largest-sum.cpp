class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        int low = nums[0];
        for(int i = 0;i<n;i++){
            low = max(low,nums[i]);
        }

        int high = 0;
        for(int i = 0;i<n;i++){
            high = high + nums[i];
        }

        while(low<=high){

            int mid = low+(high-low)/2;
            int sum = 0;
            int count = 1;

            for(int i = 0;i<n;i++){

                if(nums[i]+sum <= mid ){
                    sum = sum + nums[i];
                }

                else{
                    count++;
                    sum = nums[i];
                }

            }

            if(count<=k){
                ans = min(ans,mid);
                high = mid-1;
            }

            else{
                low = mid+1;
            }
        }
        return ans;



        
    }
};