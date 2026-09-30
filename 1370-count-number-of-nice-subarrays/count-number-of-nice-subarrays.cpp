class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // map<int, int> mp;
        // mp[0] = 1;

        // int oddcount = 0;
        // int ans = 0;
        // for (int i = 0; i < nums.size(); i++) {

        //     if (nums[i] % 2 != 0) {
        //         oddcount++;
        //     }
        //     if (mp.find(oddcount - k) != mp.end()) {
        //         ans+=mp[oddcount-k];
        //         mp[oddcount ]++;
        //     }
        //     else{
        //     mp[oddcount]++;
        //     }
        // }
        int ans = 0;
        int l = 0;
        int r = 0;
        int oddcount = 0;
        int previous = 0;
        while (r < nums.size()) {
            if (nums[r] % 2 != 0) {
                oddcount++;
            }
            // previous+=(nums[r]%2==0);

  //erase part if  oddcount is grater 
            while (oddcount > k) {
                if (nums[l] % 2 != 0) {
                    
                    oddcount--;
                }
                l++;
                previous=0;
            }
            if (oddcount == k) {
                ans++;
                while (r > l && nums[l] % 2 == 0) {
                    previous++;
                    l++;
                }
                ans += previous;
            }
            r++;
        }

        return ans;
    }
};