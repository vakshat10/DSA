class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low<=high){
            int mid = low +(high-low)/2;
            if(nums[mid]== target)  return mid;

            if(nums[low]<=nums[mid]){     // left half is sorted

                if(nums[low]<=target && nums[mid]>target)             // target lies in left sorted half?
                    high = mid-1;                                    // if yes remove the right part   
                                                         
                else {                                // target does not lie in left sorted part
                    low = mid +1;                     // remove left part
                }

            }
            else {              // right half is sorted
                           
               if(nums[mid] < target && nums[high] >= target)       // target lies in right sorted half?
                     low = mid+1;                                    // if yes remove the left part 

                     else{                                           // target does not lie in right sorted part
                        high = mid-1;                                // remove right part
                     }
               

                                 

            }
            
        }
        return -1;
        
    }
};