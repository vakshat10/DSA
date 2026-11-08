class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int low = 0, high = 0;

        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                low++;
                high++;
            }

            else if (s[i] == ')') {
                low--;
                high--;
            }

            else {
                low--;   // '*' acts as ')'
                high++;  // '*' acts as '('
            }

            // Minimum unmatched '(' cannot be negative
            if (low < 0) {
                low = 0;
            }

            // Even treating '*' as '(' cannot balance the string
            if (high < 0) {
                return false;     // "*)))"
            }
        }

        // Valid if zero unmatched '(' is possible
        return low == 0;
    }
};