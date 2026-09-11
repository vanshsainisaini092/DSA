class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int maxi = 0;

        // brute force solution

        // for (int i = 0; i < nums.size(); i++) {
        //     int zeros = 0;
        //     for (int j = i; j < nums.size(); j++) {
        //         if (nums[j] == 0) {
        //             zeros++;
        //         }
        //         if (zeros > k) {

        //             break;
        //         }
        //          maxi = max(maxi, j-i+1);
        //     }
        // }
        int zeros=0;
        int l = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] == 0) {
        //         zeros++;
        //     }

        //     if (zeros <= k) {
        //         maxi=max(maxi,i-l+1);
        //     }
        //     else{
        //         while(l<i){
                    
        //             if(nums[l]==0){
        //                 zeros--;
        //                 l=l+1;
        //                 break;
        //             }
        //             l++;
        //         }
        //     }
        // }



for(int i=0;i<nums.size();i++){

    if(nums[i]==0){
        zeros++;
    }
    if(zeros<=k){
        maxi=max(maxi,i-l+1);
    }
    else{
        if(nums[l]==0){
            zeros--;
        }
        l++;
    }
}
        return maxi;
    }
};