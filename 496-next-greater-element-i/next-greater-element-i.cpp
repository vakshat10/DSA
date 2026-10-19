class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // map: value in nums2 -> its next greater element
        unordered_map<int, int> mpp;

        // stack holds candidates for "next greater" (seen so far, to the right)
        stack<int> st;

        // walk nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {

            int x = nums2[i];

            // pop every element that is smaller than or equal to x
            // they can never be the next greater for x or for anything to the left,
            // because x is closer and at least as big
            while (!st.empty() && st.top() <= x) {
                st.pop();
            }

            // if the stack is empty, nothing greater exists on the right
            // otherwise the top is the nearest greater element
            if (st.empty()) {
                mpp[x] = -1;
            }
            else {
                mpp[x] = st.top();
            }

            // push x, it may be the next greater for elements further left
            st.push(x);
        }

        // answer the queries from nums1 using the map
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mpp[nums1[i]]);
        }

        return ans;
    }
};