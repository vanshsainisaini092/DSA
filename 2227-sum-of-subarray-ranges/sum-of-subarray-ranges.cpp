class Solution {
public:
    // for largest
    vector<int> forLargestNSL(vector<int>& arr, stack<int> st,
                              vector<int>& nsl) {
        for (int i = 0; i < arr.size(); i++) {

            while (!st.empty() && arr[st.top()] <=arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                nsl.push_back(-1);
            } else {
                nsl.push_back(st.top());
            }
            st.push(i);
        }
        return nsl;
    }
    vector<int> forLargestNSR(vector<int>& arr, stack<int> st, vector<int>& nsr)

    {
        for (int i = arr.size() - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                nsr[i] = arr.size();
            } else {
                nsr[i] = st.top();
            }
            st.push(i);
        }
        return nsr;
    }

    // for smallest
    vector<int> forSmallestNSL(vector<int>& arr, stack<int>& st,
                               vector<int>& nsl) {

        for (int i = 0; i < arr.size(); i++) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                nsl.push_back(-1);
            } else {
                nsl.push_back(st.top());
            }

            st.push(i);
        }

        return nsl;
    }

    vector<int> forSmallestNSR(vector<int>& arr, stack<int>& st,
                               vector<int>& nsr) {

        for (int i = arr.size() - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                nsr[i] = arr.size();
            } else {
                nsr[i] = st.top();
            }
            st.push(i);
        }
        return nsr;
    }

    long long subArrayRanges(vector<int>& nums) {

        stack<int> st;
        vector<int> nsl;
        vector<int> nsr(nums.size());

        // for smallest
        nsl = forSmallestNSL(nums, st, nsl);
        
        //for clearing stack
        while(!st.empty()){
            st.pop();
        }
        
        nsr = forSmallestNSR(nums, st, nsr);
        long long smallest = 0;

        for (int i = 0; i < nums.size(); i++) {
            smallest += 1ll*nums[i] * (i - nsl[i]) * (nsr[i] - i);
        }
        // for largest
        
        
        nsl.clear();
        nsr.clear();
        
        while(!st.empty()){
            st.pop();
        }
        
        nsr.resize(nums.size());
        
        
        nsl = forLargestNSL(nums, st, nsl);
        
        while(!st.empty()){
            st.pop();
        }
        nsr = forLargestNSR(nums, st, nsr);

        long long largest = 0;
        for (int i = 0; i < nums.size(); i++) {
            largest += 1ll*nums[i] * (i - nsl[i]) * (nsr[i] - i);
        }

        return largest - smallest;
    }
};