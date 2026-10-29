class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int n = intervals.size();
        vector<vector<int>> ans;

        if(n==0){
            return {newInterval};
        }

        for(int i = 0;i<n;i++){

            if(intervals[i][1]<newInterval[0]){    // current.end < new.start
                ans.push_back({intervals[i][0],intervals[i][1]});

            }

            else if(intervals[i][0] <= newInterval[1] && newInterval[0] <= intervals[i][1]){

                newInterval[0] = min(intervals[i][0],newInterval[0]);
                newInterval[1] = max(intervals[i][1],newInterval[1]);

            }

            else if(intervals[i][0]>newInterval[1]){    // current.start > new.end
                ans.push_back({newInterval[0],newInterval[1]});

                for(int j = i;j<n;j++){                               // push if anything left at last
                    ans.push_back({intervals[j][0],intervals[j][1]});

                }
                return ans;

            }

            
        }
        
        ans.push_back(newInterval);
        return ans;

    }

};
            



