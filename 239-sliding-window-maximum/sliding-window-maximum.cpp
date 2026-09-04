class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {


           while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            // for remove becouse mantain size==k window

            //check the size of window 
            if(!dq.empty() &&dq.front() <= i - k) {
                dq.pop_front();
            }

              dq.push_back(i);
            //when move to next window than first window max will store 
            if ( i>= k-1) {
                result.push_back(nums[dq.front()]);
            }   
        }
        return result;
    }
};