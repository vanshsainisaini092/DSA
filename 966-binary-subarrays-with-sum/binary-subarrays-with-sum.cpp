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
        map<int,int>mp;
        int currsum = 0;
        int count = 0;

        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {

            currsum += nums[i];
            int value=currsum-goal;

            if(mp.find(value)!=mp.end()){
                count+=mp[value];
            }
            mp[currsum]++;
        }

        return count;
    }
};