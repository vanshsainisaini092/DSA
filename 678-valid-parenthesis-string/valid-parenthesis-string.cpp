class Solution {
public:
    // bool generater(string s, int i, int count) {

    // if (count < 0) {
    //     return false;
    // }

    // if (i == s.size() && count == 0) {
    //     return true;
    // }

    // if (s[i] == '(') {
    //     return generater(s, i + 1, count + 1);
    // }

    // if (s[i] == ')') {
    //     return generater(s, i + 1, count - 1);
    // }

    // if (s[i] == '*') {
    //     return generater(s, i + 1, count + 1) ||
    //            generater(s, i + 1, count - 1) || generater(s, i + 1, count);
    // }

    //     return false;
    // }
    bool checkValidString(string s) {

        // use recursion solve but ->sc o(n)
        //  return generater(s, 0, 0);
        int min = 0;
        int max = 0;

        for (int i = 0; i < s.size(); i++) {

           
            if (s[i] == '(') {
                max++;
                min++;
            } else if (s[i] == ')') {
                if (min == 0) {

                    max--;
                } else {
                    min--;
                    max--;
                }
            } else if (s[i] == '*') {
             

                    max++;
                 if(min>0) {
                    min--;
                }
                 
            }
            if (max < 0) {
                return false;
            }
        }
        if (min == 0) {
            return true;
        }
        return false;
    }
};