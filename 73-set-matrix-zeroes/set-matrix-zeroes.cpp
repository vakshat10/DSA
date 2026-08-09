class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();       // Number of rows
        int m = matrix[0].size();    // Number of columns

        // col0 tells whether the FIRST COLUMN should become zero
        int col0 = 1;

        // Step 1: Store row and column information
        // in the first row and first column of the matrix
        for (int i = 0; i < n; i++) {

            // Check first column separately
            if (matrix[i][0] == 0)
                col0 = 0;

            for (int j = 1; j < m; j++) {

                if (matrix[i][j] == 0) {

                    // Mark this row
                    matrix[i][0] = 0;

                    // Mark this column
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2: Use the markers to set cells to zero
        // Start from row 1 and column 1
        for (int i = 1; i < n; i++) {

            for (int j = 1; j < m; j++) {

                // If row i OR column j was marked
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle FIRST ROW
        if (matrix[0][0] == 0) {

            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle FIRST COLUMN
        if (col0 == 0) {

            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};