class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //        int ans = cardPoints[0];

        // for (int j = 0; j < k - 1; j++) {
        //     int last = 0;
        //     int grater = 0;
        //     for (int i = 1; i < cardPoints.size(); i++) {

        //         if (grater < cardPoints[i]  last > cardPoints[i]) {
        //             grater = cardPoints[i];
        //         }
        //         last = grater;
        //         ans += grater;
        //     }
        // }

        int suml = 0;
        for (int i = 0; i < k; i++) {
            suml += cardPoints[i];
        }
        int maxi =0;
         maxi=max(maxi, suml);

        int j = cardPoints.size() - 1;
        for (int i = k - 1; i >= 0; i--) {
            suml -= cardPoints[i];
            suml += cardPoints[j];
            j--;
            maxi = max(maxi, suml);
        }
        return maxi;
    }
};