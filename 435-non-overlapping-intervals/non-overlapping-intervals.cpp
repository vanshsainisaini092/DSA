class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b) {

        return a.second < b.second;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>> temp;

        for (int i = 0; i < intervals.size(); i++) {
            temp.push_back({intervals[i][0], intervals[i][1]});
        }
        sort(temp.begin(), temp.end(), comp);

        int eleminate = 0;
     
        int finish = INT_MIN;
        for (auto it : temp) {
            if (it.first >= finish) {
               
                finish = it.second;
            } else {
                eleminate++;
            }
        }
       
        return eleminate;
    }
};