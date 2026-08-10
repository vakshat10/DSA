class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();        // number of rows
        int m = matrix[0].size();     // number of columns

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;

        vector<int> ans;

        while (top <= bottom && left <= right) {

            // 1. Traverse top row: left → right
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // 2. Traverse right column: top → bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Check if there is still a row left.
            // Otherwise, we may visit elements that were already traversed.
            if (top <= bottom) {

                // 3. Traverse bottom row: right → left
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Check if there is still a column left.
            // Otherwise, we may visit elements that were already traversed.
            if (left <= right) {

                // 4. Traverse left column: bottom → top
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};