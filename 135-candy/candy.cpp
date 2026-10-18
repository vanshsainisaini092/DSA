class Solution {
public:
    int candy(vector<int>& ratings) {

        // approch-> two pass greedy

        // vector<int> candy(ratings.size(), 1);
        // for (int i = 1; i < ratings.size(); i++) {

        //     // left to right

        //     if (ratings[i] > ratings[i - 1]) {
        //         candy[i] = candy[i - 1] + 1;
        //     }
        // }

        // // right to left
        // int maxi = 0;
        // for (int i = ratings.size()-2; i >= 0; i--) {
        //     if (ratings[i] > ratings[i + 1]) {
        //         //becuse in case when iterate l->R than in case current
        //         candy[i] value grater possibal>candy[i+1]

        //  candy[i] =max(candy[i], candy[i + 1] + 1);
        //     }
        // }

        // for (int i = 0; i < candy.size(); i++) {
        //     maxi += candy[i];
        // }
        // return maxi;

        //  2. approch -> slope-based approch

        int candy = ratings.size();
        int i = 1;
        while (i < ratings.size()) {
            int peak = 0;

            // for incriging order

            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }
            while (ratings[i] > ratings[i - 1]) {
                peak++;
                candy += peak;
                if (i == ratings.size() - 1) {
                    return candy;
                }
                i++;
            }

            // for decringing order
            int dip = 0;

            while (i < ratings.size() && ratings[i] < ratings[i - 1]) {
                dip++;
                candy += dip;
                i++;
            }
            // in case when mountain complete ->pick largest(peak,dip) peak of
            // mountain
            candy -= min(peak, dip);
        }
        return candy;
    }
};