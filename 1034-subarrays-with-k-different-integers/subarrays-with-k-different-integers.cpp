class Solution {
public:

    int atMost(vector<int>& nums, int k){

        if(k==0) return 0;

        int left = 0,count = 0,ans = 0;
        unordered_map <int,int> mpp;


        for(int right = 0;right<nums.size();right++){

            mpp[nums[right]]++;

            if(mpp[nums[right]]==1){
                count++;
            }

            while(count>k){
                mpp[nums[left]]--;

                if(mpp[nums[left]]==0){
                    count--;
                }

                left++;
            }

            ans = ans + (right-left +1);



        }
        return ans;



    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return (atMost(nums,k)-atMost(nums,k-1));
        
    }
};