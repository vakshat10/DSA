class Solution {
public:

    long long merge(vector<int>& nums, int low, int mid, int high) {

        long long count = 0;

        // Step 1: Count reverse pairs
        int j = mid + 1;

        for (int i = low; i <= mid; i++) {

            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }

            count += j - (mid + 1);
        }

        // Step 2: Normal merge
        vector<int> temp;

        int i = low;
        j = mid + 1;

        while (i <= mid && j <= high) {

            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        // Remaining left elements
        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        // Remaining right elements
        while (j <= high) {
            temp.push_back(nums[j]);
            j++;
        }

        // Copy sorted elements back
        for (int k = low; k <= high; k++) {
            nums[k] = temp[k - low];
        }

        return count;
    }


    long long mergeSort(vector<int>& nums, int low, int high) {

        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        long long count = 0;

        // Count reverse pairs in left half
        count += mergeSort(nums, low, mid);

        // Count reverse pairs in right half
        count += mergeSort(nums, mid + 1, high);

        // Count reverse pairs between both halves
        count += merge(nums, low, mid, high);

        return count;
    }


    int reversePairs(vector<int>& nums) {

        int n = nums.size();

        return mergeSort(nums, 0, n - 1);
    }
};