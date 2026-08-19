class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int low = 1;
        int high = n - 2;

        // If only one element is present
        if (n == 1) {
            return nums[0];
        }

        // Check if first element is single
        if (nums[0] != nums[1]) {
            return nums[0];
        }

        // Check if last element is single
        if (nums[n - 1] != nums[n - 2]) {
            return nums[n - 1];
        }

        // Binary search
        while (low <= high) {

            int mid = low + (high - low) / 2;

            // mid itself is the single element
            if (nums[mid] != nums[mid - 1] &&
                nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // mid is paired with the left element
            else if (nums[mid] == nums[mid - 1]) {

                // Pair should start at even index
                if (mid % 2 == 0) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            // mid is paired with the right element
            else if (nums[mid] == nums[mid + 1]) {

                // Pair should start at even index
                if (mid % 2 == 0) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};