class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);     // default -1
        stack<int> st;              // candidates for "next greater"

        // walk the doubled array from right to left
        for (int i = 2 * n - 1; i >= 0; i--) {

            int x = nums[i % n];    // real element at doubled position i

            // pop everything smaller than or equal to x
            // they can never be the next greater for x or anything to its left
            while (!st.empty() && st.top() <= x) {
                st.pop();
            }

            // only record answers for the real indices (first copy)
            if (i < n) {
                if (!st.empty()) {
                    ans[i] = st.top();   // nearest greater element
                }
                // else ans[i] stays -1
            }

            // push x, it may be the next greater for elements to its left
            st.push(x);
        }

        return ans;
    }
};