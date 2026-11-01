class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int low = 0,high = 0;

        for(int i = 0;i<n;i++){

            if(s[i] == '('){
                low++;
                high++;
            }

            else if(s[i] == ')'){
                low--;
                high--;
            }

            else{
                low--;   // * -> ')'
                high++;  // * -> '('
            }

            if(low < 0){
                low = 0;
            }

            if(high<0){            // "*)))"
                return false;
            }
        }

        

        if(low == 0){
            return true;
        }

        else{ 
            return false;
            }
        
    }
};