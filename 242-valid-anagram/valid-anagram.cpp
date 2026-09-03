class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n!=m) return false;

        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;

        for(int i =0;i<n;i++){
            freq1[s[i]]++;
        }
        for(int i =0;i<m;i++){
            freq2[t[i]]++;
        }

        for(int i = 0;i<n;i++){      // no of elements are same n=m
            if(freq1[s[i]] == freq2[s[i]]){

            }
            else{
                return false;
            }
        }
        return true;


        
    }
};