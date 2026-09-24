class Solution {
public:
    int slidingwindow(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;

        int count = 0;
        map<int, int> mp;

        while (r < nums.size()) {

            mp[nums[r]]++;

            // if (mp.size() < k) {
            //     count += r - l + 1;
            // }

            while (mp.size() > k) {

                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                l++;
            }
                count += r - l + 1;

            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return slidingwindow(nums, k) - slidingwindow(nums, k - 1);
    }
};