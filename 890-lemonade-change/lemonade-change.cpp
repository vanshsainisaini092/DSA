class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int i = 0;
        int j = 0;
        int k = 0;

        int l = 0;
        while (l < bills.size()) {

            if (bills[l] == 5) {
                i++;
            } else if (bills[l] == 10) {

                if (i) {

                    j++;
                    i--;
                } else {
                    return false;
                }
            }

            else {
                if (j > 0 && i > 0) {
                    j--;
                    i--;
                } else if (i >= 3) {
                    i -= 3;
                } else {
                    return false;
                }
            }
            l++;
        }
        return true;
    }
};