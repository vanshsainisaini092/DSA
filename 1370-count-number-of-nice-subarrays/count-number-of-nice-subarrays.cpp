class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = 1;

        int oddcount = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] % 2 != 0) {
                oddcount++;
            }
            if (mp.find(oddcount - k) != mp.end()) {
                ans+=mp[oddcount-k]; 
                mp[oddcount ]++;
            }
            else{
            mp[oddcount]++;
            }
        }
        return ans;
    }
};