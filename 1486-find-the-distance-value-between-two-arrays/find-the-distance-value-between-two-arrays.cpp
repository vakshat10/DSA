class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());

        int n = arr1.size();
        int m = arr2.size();

        int j = 0; // never reset

        int count = 0;

        for(int i = 0;i<n;i++){

            int low = arr1[i] - d;
            int high = arr1[i] + d;

            while(j<m && arr2[j]<low){
                j++;
            }

            if(j==m || arr2[j]> high){
                count++;
            }


        }

        return count;
        
    }
};