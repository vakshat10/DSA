class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        int ans = 1;
        if(n==0){
            return 0;
        }

        unordered_set<int> st;
        for(int x : nums){
            st.insert(x);
        }

        for(int a : st){
            
            int count = 1;
            if(st.find(a-1) == st.end()){    // a-1 does not exist   , a is starting element of sequence
                
            while (st.find(a+1)!= st.end()){ // a+1 exist in set
                count++;
                a++;
            }
            ans = max(count,ans);
            }



        }
        return ans;


        
    }
};