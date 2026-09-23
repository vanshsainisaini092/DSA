class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int maxi = 0;

        int l = 0;
        int r = 0;
        map<int, int> mp;
        int k = 0;
        while (r < fruits.size()) {

            mp[fruits[r]]++;
            while (mp.size() > 2) {

                mp[fruits[l]]--;

                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }
                l++;

                // else {
                //     maxi = max(maxi, (r - l + 1));
                // }
            }

            maxi = max(maxi, (r - l + 1));
            r++;
        }
        return maxi;
    }
};