// Next Smaller or Equal Element
vector<int> NSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && arr[st.top()] >=arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            nse[i] = st.top();
        }

        st.push(i);
    }

    return nse;
}

// Previous Strictly Smaller Element
vector<int> PSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> pse(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {

        while (!st.empty() && arr[st.top()] > arr[i]) {
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
    int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    int mod = 1e9 + 7;

    vector<int> nse = NSE(arr);
    vector<int> pse = PSE(arr);

    long long sum = 0;

    for (int i = 0; i < n; i++) {

        int left = i - pse[i];
        int right = nse[i] - i;

        // Contribution of current element
        sum += 1LL * arr[i] * left * right;
    }

    return sum % mod;

    }
};