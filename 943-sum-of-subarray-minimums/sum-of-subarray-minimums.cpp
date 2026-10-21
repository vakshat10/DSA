class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1000000007;

        vector<int> pse(n, -1);   // previous smaller (or equal) index, -1 if none
        vector<int> nse(n, n);    // next strictly smaller index, n if none
        stack<int> st;

        // previous smaller or equal: walk left to right
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }

        // clear the stack for reuse
        while (!st.empty()) {
            st.pop();
        }

        // next strictly smaller: walk right to left
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()){
                 nse[i] = st.top();
            }
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            // arr[i] * (number of subarrays where it is the minimum)
            ans = (ans + (arr[i] * left   * right))% MOD;
        }

        return ans;
    }
};