class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        int n = arr.size();

        vector<int> temp = arr;
        sort(temp.begin(),temp.end());

        unordered_map<int,int> mpp;  // {element,rank}

        int rank = 1;

        for(int i = 0;i<n;i++){
            if(mpp.find(temp[i]) == mpp.end()){
                mpp[temp[i]] = rank;
                rank++;
            }
        }

        vector<int> ans;

        for(int i = 0;i<n;i++){

            ans.push_back(mpp[arr[i]]);

        }

        return ans;
        

        
    }
};