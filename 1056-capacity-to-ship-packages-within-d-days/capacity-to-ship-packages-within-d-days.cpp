class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int n = weights.size();
        int ans = INT_MAX;

        int low = weights[0];

        // Minimum capacity = maximum weight
        for(int i = 0; i < n; i++) {
            low = max(low, weights[i]);
        }

        int high = 0;

        // Maximum capacity = total weight
        for(int i = 0; i < n; i++) {
            high += weights[i];
        }

        // Binary search on capacity
        while(low <= high) {

            int mid = low + (high - low) / 2;  // mid is capacity

            int currentwt = 0;
            int dayneeded = 1;

            // Calculate days needed for capacity mid
            for(int i = 0; i < n; i++) {

                if(currentwt + weights[i] <= mid) {
                    currentwt += weights[i];
                }
                else {
                    // Start a new day
                    dayneeded++;
                    currentwt = weights[i];
                }
            }

            // Capacity works, try smaller capacity
            if(dayneeded <= days) {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else {
                // Capacity is too small
                low = mid + 1;
            }
        }

        return ans;
    }
};

