class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        int count = 0;
        for(int i = n-1;i>=0;i--){
            
            if(s[i]== ' '){
                if(count!=0){
                    for (int j = i+1;j<=i+count;j++){
                        ans = ans + s[j];
                }
                
                   ans = ans + ' ';
                
                }
                count = 0;
                
            }
            else{
                count++;
            }
        }

        if(count!=0){
            for(int i = 0;i<count;i++){
                ans = ans +s[i];
            }
            ans = ans + ' ';
        }
        ans.pop_back();   //removes the last character of the string. extra space at last

        return ans;
        
    }
};