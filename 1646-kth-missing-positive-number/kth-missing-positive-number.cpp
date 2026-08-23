class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int n = arr.size();

        for(int i = 0; i < n; i++) {

            // Number of missing elements before arr[i]
            int missing = arr[i] - (i + 1);

            // kth missing number is before arr[i]
            if(missing >= k) {
                return i + k;
            }
        }

        // kth missing number is after the last element
        return n + k;
    }
};