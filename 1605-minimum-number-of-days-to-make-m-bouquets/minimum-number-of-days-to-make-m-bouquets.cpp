class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();

        // Not enough flowers to make m bouquets
        if (1LL * m * k > n)
            return -1;

        int low = 1;
        int high = bloomDay[0];
        int ans = INT_MAX;

        // Find maximum bloom day
        for (int i = 0; i < n; i++) {
            high = max(high, bloomDay[i]);
        }

        // Binary search on the answer (day)
        while (low <= high) {

            int mid = low + (high - low) / 2;

            int count = 0;
            int boq = 0;

            // Check how many bouquets can be made by day mid
            for (int i = 0; i < n; i++) {

                if (bloomDay[i] <= mid) {
                    count++;

                    // k adjacent flowers make one bouquet
                    if (count == k) {
                        boq++;
                        count = 0;
                    }
                }
                else {
                    // Break in adjacency
                    count = 0;
                }
            }

            // Enough bouquets → try an earlier day
            if (boq >= m) {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else {
                // Not enough bouquets → need more days
                low = mid + 1;
            }
        }

        return ans;
    }
};