class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();

        // Both strings must have the same length
        if(n != m) return false;

        // Every rotation of s will appear in s + s
        if((s + s).find(goal) != string::npos){
            return true;
        }

        return false;
    }
};