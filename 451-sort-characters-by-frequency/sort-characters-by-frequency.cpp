class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        string ans = "";

        unordered_map<char,int> freq;
        
        for(char c : s){
            freq[c]++; 
        }

        for(int i = 0;i<n;i++){

        int maxFreq = 0;
        char maxChar;

        for(auto it : freq){
            if(it.second>maxFreq){
                maxFreq = it.second;
                maxChar = it.first;
            }
        }

        for(int i = 0;i<maxFreq;i++){
             ans+= maxChar;
        }

        freq.erase(maxChar);

        }

    
        return ans;
    }
};