class Solution {
public:
    int smallestNumber(int n, int t) {

        while (true) {

            int temp = n;
            int mul = 1;

            // Find product of digits
            while (temp > 0) {
                int x = temp % 10;
                mul = mul * x;
                temp = temp / 10;
            }

            // Check divisibility
            if (mul % t == 0) {
                return n;
            }

            // Try next number
            n = n + 1;
        }
    }
};