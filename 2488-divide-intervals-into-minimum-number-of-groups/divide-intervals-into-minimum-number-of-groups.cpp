class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        vector<int> arrival;
        vector <int> departure;

        for(int i = 0;i<n;i++){

            arrival.push_back(intervals[i][0]);
            departure.push_back(intervals[i][1]);

        }

        sort(arrival.begin(),arrival.end());
        sort(departure.begin(),departure.end());

        int count = 0;
        int ans = 0;
        int i = 0,j= 0;

        while(i<n){

            if(arrival[i]<=departure[j]){
                count++;
                i++;
            }

            else{
                count--;
                j++;
            }

            ans = max(ans,count);
        }

        return ans;
        
        
            

            
        
    }
};