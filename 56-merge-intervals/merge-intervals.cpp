class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<pair<int, int>>temp;
        for (int i = 0; i < intervals.size(); i++) {
            temp.push_back({intervals[i][0], intervals[i][1]});
        }
 
        // compratable function call
        sort(temp.begin(), temp.end(), comp);

        int finish = temp[0].second;
        int start = temp[0].first;

        vector<vector<int>>ans;
        for (auto it : temp) {

            if (finish < it.first) {
                ans.push_back({start, finish});
                start = it.first;
                finish = it.second;
            } else {
                if (finish < it.second) {
                    finish = it.second;
                }
            }
        }
        ans.push_back({start, finish});
        return ans;
    }
};