class Solution {
public:
    int candy(vector<int>& ratings) {

        vector<int> candy(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {

            // left to right

            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }

        // right to left
        int maxi = 0;
        for (int i = ratings.size()-2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candy[i] =max(candy[i], candy[i + 1] + 1);
            }
        }

        for (int i = 0; i < candy.size(); i++) {
            maxi += candy[i];
        }

        //     // for all mid case
        //     if (i > 0 || i + 1 < ratings.size()) {
        //         if (ratings[i] > ratings[i - 1] ||
        //             ratings[i] > ratings[i + 1]) {
        //             candy++;
        //         }
        //     }
        //     //  handel initial case

        //     else if (i == 0 && i + 1 < ratings.size()) {
        //         if (ratings[i] < ratings[i + 1]) {
        //             candy++;
        //         }
        //     }

        //     // handel last index

        //     else if (i == ratings.size() - 1 && i > 0) {
        //         if (ratings[i] > ratings[i - 1]) {
        //             candy++;
        //         }
        //     }

        return maxi;
    }
};