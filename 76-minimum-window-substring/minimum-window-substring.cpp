class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size()) {
            return "";
        }
       unordered_map<char, int> mp;
        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
        }
        int l = 0;
        int requiredsize = t.size();
        int minwindow = INT_MAX;
        int start = 0;

        int r = 0;
        while (r < s.size()) {

            if (mp[s[r]] > 0) {
                requiredsize--;
               
            }
             mp[s[r]]--;

            // shrinke the window

            while (requiredsize == 0) {

                int windowsize = r - l + 1;
                if (minwindow > windowsize) {
                    start = l;
                    minwindow = windowsize;
                }
                // shrink
                mp[s[l]]++;
                // check if after shrink size incrise than increse value of
                // requiredsize
                if (mp[s[l]] > 0) {
                    requiredsize++;
                }
                l++;
            }
            r++;
        }
        return minwindow == INT_MAX ? "" : s.substr(start, minwindow);
    }
};