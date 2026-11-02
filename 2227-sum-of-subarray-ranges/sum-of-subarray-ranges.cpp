// Next Greater Element (strictly greater)
vector<int> NGE(vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] <= nums[i]) {
            st.pop();
        }

        if (!st.empty()) {
            nge[i] = st.top();
        }

        st.push(i);
    }

    return nge;
}

// Previous Greater or Equal Element
vector<int> PGE(vector<int>& nums) {
    int n = nums.size();
    vector<int> pge(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            st.pop();
        }

        if (!st.empty()) {
            pge[i] = st.top();
        }

        st.push(i);
    }

    return pge;
}

// Next Smaller Element (strictly smaller)
vector<int> NSE(vector<int>& nums) {
    int n = nums.size();
    vector<int> nse(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }

        if (!st.empty()) {
            nse[i] = st.top();
        }

        st.push(i);
    }

    return nse;
}

// Previous Smaller or Equal Element
vector<int> PSE(vector<int>& nums) {
    int n = nums.size();
    vector<int> pse(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }

        if (!st.empty()) {
            pse[i] = st.top();
        }

        st.push(i);
    }

    return pse;
}

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;

        vector<int> nge = NGE(nums);
        vector<int> pge = PGE(nums);
        vector<int> nse = NSE(nums);
        vector<int> pse = PSE(nums);

        for (int i = 0; i < n; i++) {

            // Contribution as maximum
            int left1 = i - pge[i];
            int right1 = nge[i] - i;
            long long maxi = 1LL * left1 * right1;

            // Contribution as minimum
            int left2 = i - pse[i];
            int right2 = nse[i] - i;
            long long mini = 1LL * left2 * right2;

            // Add maximum contribution - minimum contribution
            sum += (maxi - mini) * nums[i];
        }

        return sum;
    }
};