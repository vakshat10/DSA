class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        int sign = 1;
        long long ans = 0;

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Handle the sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // 3. Read digits and build the number
        while (i < n && s[i] >= '0' && s[i] <= '9') {  // while loop automatically exit if condition is not followed
            int digit = s[i] - '0';  // convert char to int
            ans = ans * 10 + digit;

            // 4. Handle overflow
            if (sign * ans <= INT_MIN) {
                return INT_MIN;
            }
            if (sign * ans >= INT_MAX) {
                return INT_MAX;
            }

            i++;
        }

        // 5. Apply the sign
        return sign * ans;
    }
};