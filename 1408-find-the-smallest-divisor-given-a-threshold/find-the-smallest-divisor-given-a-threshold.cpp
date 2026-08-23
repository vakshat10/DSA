class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        int n = nums.size();

        int ans = INT_MAX;

        int high = nums[0];

        for(int i = 0;i<n;i++){
          high = max(high,nums[i]);
        }

         int low = 1;

         while(low<=high){

            int mid = low +(high-low)/2;
    
    
        int sum = 0;

        for(int j = 0;j<n;j++){
            int value =  (nums[j]+mid-1)/mid;    // nums[j]/mid
            sum = sum + value;                    
        }

        if(sum<=threshold){
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