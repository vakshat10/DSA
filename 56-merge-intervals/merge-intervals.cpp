class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());

        if(n==1){ 
            ans = intervals;
            return ans;
        }
            int a = intervals[0][0];
            int b = intervals[0][1];

            for(int i = 1; i<n; i++){
            
            int c = intervals[i][0];
            int d = intervals[i][1];

            

            if(c<=b){     // overlaping exist
              b = max(b,d);
              

                
            }

            else{                      // no overlapping

                ans.push_back({a,b});
                a = c;
                b = d;
                
                
            }



        }
        ans.push_back({a,b});
        return ans;
    }
};