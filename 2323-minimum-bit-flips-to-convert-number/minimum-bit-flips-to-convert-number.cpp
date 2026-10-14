class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal;  // XOR gives 1 where bits differ
        int count = 0;

        while (n > 1) {
            if ((n & 1) == 1) {  //    n%2   , Check if the last bit is 1
                count++;
            }
            n = n >> 1;  //    n/2   ,Remove the last bit
        }

        if (n == 1) {  // Count the final remaining bit
            count++;
        }

        return count;  // Return minimum flips required
    }
};