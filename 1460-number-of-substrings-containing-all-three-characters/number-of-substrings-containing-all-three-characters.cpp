class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.size();

        int last[3] = {-1,-1,-1};  // 0->a , 1-> b , 2-> c

        int ans = 0;

        for(int i = 0;i<n;i++){

            if(s[i]== 'a'){
                last[0] = i;
            }

            else if(s[i]== 'b'){
                last[1] = i;
            }

            else{
                last[2] = i;
            }

            if(last[0]>-1 && last[1]>-1 && last[2]>-1 ){  // a,b,c exist in window

            int mini = min(min(last[0],last[1]),last[2]);

            ans = ans + mini +1;

            }

        }

        return ans;


        

    }
};