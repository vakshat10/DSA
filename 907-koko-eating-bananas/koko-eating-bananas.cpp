class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();

        // Minimum possible eating speed
        int low = 1;

        // Maximum possible eating speed
        int high = piles[0];

        int ans = 1;

        // Find the largest pile
        for (int i = 0; i < n; i++) {
            high = max(high, piles[i]);
        }

        // Binary search on eating speed
        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long hour = 0;

            // Calculate total hours needed at speed mid
            for (int i = 0; i < n; i++) {

                // Ceiling division
                int time = (piles[i] + mid - 1) / mid;

                hour = hour + time;
            }

            // If Koko can finish within h hours,
            // try a smaller speed
            if (hour <= h) {
                ans = mid;
                high = mid - 1;
            }

            // If it takes more than h hours,
            // increase the speed
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};