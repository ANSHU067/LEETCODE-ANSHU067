class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;

        // Count number of 1s
        for (char c : s) {
            if (c == '1') {
                ones++;
            }
        }

        string ans;

        // Put all 1s except one at the beginning
        for (int i = 0; i < ones - 1; i++) {
            ans += '1';
        }

        // Put all 0s in the middle
        for (int i = 0; i < s.length() - ones; i++) {
            ans += '0';
        }

        // One 1 must be at the end to make it odd
        ans += '1';

        return ans;
    }
};