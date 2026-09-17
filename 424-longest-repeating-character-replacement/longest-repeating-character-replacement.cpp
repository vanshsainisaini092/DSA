class Solution {
public:
    int characterReplacement(string s, int k) {

        // int maxi = 0;
        // int other = 0;
        // int ans=0;
        // for (int j = 0; j < s.size(); j++) {
        //     int hash[126] = {0};
        //     maxi = 0;

        //     for (int i = j; i < s.size(); i++) {

        //         hash[s[i]]++;
        //         maxi = max(maxi, hash[s[i]]);

        //         other = (i - j + 1) - maxi;
        //         if (other <= k) {
        //             ans = max(ans, i - j + 1);
        //         } else {
        //             break;
        //         }
        //     }
        // }

        map<char, int> mp;
        int left = 0;
        int size = 0;
        int maxi = 0;
        int ans = 0;
        int otherchar = 0;
        int key = 0;
        for (int r = 0; r < s.size(); r++) {

            mp[s[r]]++;

            for (auto it : mp) {
                maxi = max(maxi, it.second);
                if (maxi == it.second) {
                    key = it.first;
                }
            }
            size = r - left + 1;
            otherchar = size - maxi;

            if (otherchar <= k) {
                ans = max(ans, size);
            } else {
                mp[s[left]]--;
                left++;
            }
        }
        return ans;
    }
};