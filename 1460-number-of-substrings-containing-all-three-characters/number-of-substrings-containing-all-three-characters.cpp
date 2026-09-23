class Solution {
public:
    int numberOfSubstrings(string s) {

        // brute force approch

        map<char, int> mp;
        // int count = 0;
        // for (int i = 0; i < s.size(); i++) {
        //     mp.clear();
        //     for (int j = i; j<s.size(); j++) {
        //         mp[s[j]]++;
        //         if (mp.size() == 3) {
        //             count++;
        //         }
        //     }
        // }
        // return count;

        int r = 0;
        int l = 0;
        int result = 0;
        while (r < s.size()) {
            mp[s[r]]++;
            while (mp.size() == 3) {

                result += s.size() - r;
                mp[s[l]]--;

                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }

            r++;
        }
        return result;
    }
};