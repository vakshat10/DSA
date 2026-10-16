class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int n = g.size();
        int m = s.size();

        int count = 0;
        int i = 0; // child pointer
        int j = 0; // cookie pointer

        while(i<n && j<m){

            if(s[j] >= g[i]){
                count++;
                j++;  // that cookie is consumed
                i++;  // child has eaten
            }

            else if(s[j] < g[i]){
                j++;  // cookie is small
            }
        }

        return count;
        
    }
};