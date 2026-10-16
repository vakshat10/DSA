class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        string ans = "";

        // Even if every digit is 9, we cannot reach sum, so no good integer exists
        // 9LL makes the multiplication happen in long long, so it cannot overflow
        if (sum > 9LL * num) {
            return ans;
        }

        int nine = sum / 9;        // how many 9s fit into sum
        int leftover = sum % 9;    // what remains after the 9s (0 to 8)
        int used = 0;              // how many digits we have written so far

        // Step 1: write the 9s first (big digits first gives the largest score)
        for (int i = 0; i < nine; i++) {
            ans += '9';
            used++;
        }

        // Step 2: write the leftover digit, if there is one
        // '0' + leftover turns the number (for example 8) into the character '8'
        if (leftover > 0) {
            ans += ('0' + leftover);
            used++;
        }

        // Step 3: fill the remaining positions with zeros so the length is exactly num
        for (int i = used; i < num; i++) {
            ans += '0';
        }

        return ans;
    }
};