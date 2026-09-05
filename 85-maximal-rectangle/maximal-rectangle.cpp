class Solution {
public:
    int hito(vector<int> heights) {
        stack<int> st;
        int maxarea = 0;
        int nse = -1;
        int pse = -1;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                nse = i;
                st.pop();
                pse = st.empty() ? -1 : st.top();
                // for max area;
                maxarea = max(maxarea, heights[element] * (nse - pse - 1));
            }

            st.push(i);
        }

        while (!st.empty()) {

            nse = heights.size();
            int element = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            // for max
            maxarea = max(maxarea, heights[element] * (nse - pse - 1));
        }
        return maxarea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
  //c style
        // int prefixsum[matrix.size()][matrix[0].size()];
        
        //cpp style
        vector<vector<int>>prefixsum(matrix.size(),
                                      vector<int>(matrix[0].size()));

        for (int i = 0; i < matrix[0].size(); i++) {
            int sum = 0;
            for (int j = 0; j < matrix.size(); j++) {
                if (matrix[j][i] == '0') {
                    sum = 0;
                } else {
                    sum += matrix[j][i]-'0';
                }
                prefixsum[j][i] = sum;
            }
        }

        int maxarea = 0;
        for (int i = 0; i < matrix.size(); i++) {

            maxarea = max(maxarea, hito(prefixsum[i]));
        }

        return maxarea;
    }
};