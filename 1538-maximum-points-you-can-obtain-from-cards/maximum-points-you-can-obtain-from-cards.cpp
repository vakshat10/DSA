class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int left = k - 1;     // last card taken from the left
        int right = n - 1;    // next card to take from the right

        // start with all k cards from the left
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }

        int ans = sum;

        // give up one left card, take one right card
        while (left >= 0) {
            sum = sum - cardPoints[left] + cardPoints[right];
            ans = max(ans, sum);
            left--;
            right--;
        }

        return ans;
    }
};