class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> ans;
        int i = 0;

        // first part that is value no appare inside pair
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // mid ->merge part
        //   make pair ->min(starting point of pair )  and max(ending point of
        //   pair )
        int mini = newInterval[0];
        int maxi = newInterval[1];
        while (i < intervals.size() && intervals[i][0] <= maxi) {

            mini = min(mini, intervals[i][0]);
            maxi = max(maxi, intervals[i][1]);
            i++;
        }
        ans.push_back({mini, maxi});

        // last part

        while (i < intervals.size()) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};