class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        // If only one element, it is the peak
        if (n == 1) return 0;

        // Check first element
        if (nums[0] > nums[1]) return 0;

        // Check last element
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int low = 1;
        int high = n - 2;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // If mid is greater than both neighbours,
            // then mid is a peak
            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
                return mid;
            }

            
            else if (nums[mid] < nums[mid - 1]) {
                high = mid - 1;
            }

            
            else if(nums[mid]<nums[mid+1]) {
                low = mid + 1;
            }
        }

        return -1;
    }
};