class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> ans;
        stack<int> st;

        // for(int i=0;i<i<temperatures.size();i++){
        //     bool check=true;
        //     for(int j=i+1;j<temperatures.size()-1;j++){
        //         if(temperatures[i]<temperatures[j]){
        //             ans.push_back(j-i);
        //             check=false;
        //             break;
        //         }
        //     }
        //     if(check){
        //         ans.push_back(0);
        //     }
        // }

        for (int i = temperatures.size() - 1; i >= 0; i--) {

            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans.push_back(0);
            } else {
                if (temperatures[st.top()] > temperatures[i]) {
                    ans.push_back(st.top() - i);
                }
            }

            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};