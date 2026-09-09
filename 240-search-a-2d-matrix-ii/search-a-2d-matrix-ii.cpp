class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();            // rows 
        int n = matrix[0].size();         // col

        int i = 0;
        int j = n-1;

        while(i<m && j>=0){
            int currentElement = matrix[i][j];

            if(currentElement == target){
                return true;
            }

            if(currentElement < target){
                i++;
            }
            else if(currentElement > target){
                j--;
            }

        }
        return false;

        
    }
};