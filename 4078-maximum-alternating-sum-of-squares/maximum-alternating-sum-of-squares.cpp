class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int minusCount = n / 2;

        // Only squares matter, so convert every element to its square
        vector<long long> squares;
        for (int i = 0;i<n;i++) {
            squares.push_back((long long)nums[i] * nums[i]);
        }

        // Sort so the smallest squares come first
        sort(squares.begin(), squares.end());

        long long score = 0;

        // Smallest squares go in the '-' slots
        for (int i = 0; i < minusCount; i++) {
            score -= squares[i];
        }

        // Largest squares go in the '+' slots
        for (int i = minusCount; i < n; i++) {
            score += squares[i];
        }

        return score;
    }
};