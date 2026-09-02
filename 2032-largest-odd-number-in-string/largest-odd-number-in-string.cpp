class Solution {
public:
    string largestOddNumber(string num) {

        int n = num.size();

        // Find the rightmost odd digit
        for(int i = n - 1; i >= 0; i--) {

            // Convert character digit to integer and check if odd
            if((num[i] - '0') % 2 == 1) {

                // Take the string from index 0 to i
                return num.substr(0, i + 1);
            }
        }

        // No odd digit found
        return "";
    }
};