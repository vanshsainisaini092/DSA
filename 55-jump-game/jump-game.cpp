class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        int i = 0;
                if(nums.size()==1){
            return true;
        }
        while (i < nums.size()) {

            if(maxi <i){
                return false;
            }
           maxi=max(maxi,nums[i]+i);
            i++;
        }
        return true;
    }
};