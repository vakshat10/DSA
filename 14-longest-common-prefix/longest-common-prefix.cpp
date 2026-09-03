class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        if(n==0){
            return ans;
        }
        if(n==1){
            return strs[0];
        }
        int num = INT_MAX; // stores no of same elements
        for(int i = 0;i<n-1;i++){
            int count = 0;
            for(int j = 0;j<strs[i].size() && j<strs[i+1].size();j++){
                
                if(strs[i][j]==strs[i+1][j]){
                    count++;
                }
                else{
                    break;
                }
                
            }
            num = min(num,count);

        }
        for(int i = 0;i<num;i++){
            ans += strs[0][i];
        }
        return ans;
        
    }
};