class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int rotation = 0;

        long long leftsum = 0;
        long long total = 0;

        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }
        for (int i = 0; i < nums.size() / 2; i++) {
            leftsum += nums[i];
        }

        for (int k = 0; k < nums.size(); k++) {

            long long rightsum = total - leftsum;

            if (leftsum > rightsum) {
                rotation++;
            }

            // for next k value;
            
                leftsum -= nums[k];

                // add

                leftsum += nums[(k + nums.size()/2) % nums.size()];
            
        }

        return rotation;
    }
};