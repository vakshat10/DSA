class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();  // no of  total flowers

        if( 1LL * m*k>n) return -1;

        int low = 1;
        int high = bloomDay[0];
        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {
            high = max(high, bloomDay[i]);
        }

        while(low<=high){

        int mid = low + (high-low)/2;

            int count = 0;
            int boq = 0;

            for(int i = 0; i < n; i++) {

                if(bloomDay[i] <= mid) {
                    count++;

                    if(count == k) {
                        boq++;
                        count = 0;

                        
                    }
                }
                else {
                    count = 0;
                    
                }
            }
            if(boq >=m) {
              ans = min(ans,mid);
              high = mid-1;
            }
                            
            else if(boq<m){
                low = mid+1;
            }
            
             
        }
        return ans;
        
        

       
        
    }
};