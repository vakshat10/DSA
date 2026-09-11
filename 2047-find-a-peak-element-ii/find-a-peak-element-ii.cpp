int maxRowIndex(vector<vector<int>>& mat, int m, int mid) {
    int max = -1;
    int index = -1;

    // Find the row index of the maximum element in the mid column
    for(int i = 0; i < m; i++) {
        if(mat[i][mid] > max) {
            max = mat[i][mid];
            index = i;
        }
    }

    return index;
}

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();       // Number of rows
        int n = mat[0].size();    // Number of columns

        int low = 0;
        int high = n - 1;

        // Binary search on columns
        while(low <= high) {
            int mid = low + (high - low) / 2;

            // Find row of maximum element in mid column
            int row = maxRowIndex(mat, m, mid);

            // Check left and right neighbours
            int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
            int right = mid + 1 < n ? mat[row][mid + 1] : -1;

            // Current element is greater than both neighbours
            if(mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            }

            // Left neighbour is greater → search left half
            else if(mat[row][mid] < left) {
                high = mid - 1;
            }

            // Right neighbour is greater → search right half
            else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};