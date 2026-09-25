class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        //   int count=0;
        // brute force approch

        // for (int i = 0; i < nums.size(); i++) {
        //     int sum = 0;
        //     for (int j = i; j < nums.size(); j++) {
        //         sum += nums[j];
        //         if (sum == goal) {
        //             count++;
        //         }
        //     }

        // }

        // better approch

        // map<int,int>mp;
        // int currsum = 0;
        // int count = 0;

        // mp[0] = 1;
        // for (int i = 0; i < nums.size(); i++) {

        //     currsum += nums[i];
        //     int value=currsum-goal;

        //     if(mp.find(value)!=mp.end()){
        //         count+=mp[value];
        //     }
        //     mp[currsum]++;
        // }

        int count = 0;
        int l = 0;
        long long sum = 0;
        int r = 0;
        int count_zeros = 0;
        while (r < nums.size()) {
            sum += nums[r];
            while (l < r && (nums[l] == 0 || sum > goal)) {

                if (nums[l] == 0) {
                    count_zeros++;
                } else {
                    count_zeros = 0;
                }

                sum -= nums[l];
                l++;
            }
            if (sum == goal) {
                count = count + 1 + count_zeros;
            }
            r++;
        }

        return count;
    }
};