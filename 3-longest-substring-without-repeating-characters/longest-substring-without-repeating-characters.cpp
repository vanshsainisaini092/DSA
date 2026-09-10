class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.size() == 1) {
            return 1;
        }
        int maxi = 0;
        // for (int i = 0; i < s.size() ; i++) {
        //     vector<int> mp(256, 0);

        //     for (int j = i ; j < s.size(); j++) {
        //         if (mp[s[j]] == 1) {

        //             break;
        //         }
        //         mp[s[j]] = 1;
        //         maxi = max(maxi, j - i+1);
        //     }
        // }

        // optimal approch

        map<char, int> mp;
        int l = 0;
        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) != mp.end()) {
                l=max(l,mp[s[i]]+1);
              
            } 
                mp[s[i]] = i;
              
              maxi = max(maxi, i - l + 1);
        }
        return maxi;
    }
};