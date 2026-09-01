class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for (int x = low; x <= high; x++) {

            string s = to_string(x);

            // Odd number of digits -> not symmetric
            if (s.length() % 2 != 0) {
                continue;
            }

            int n = s.length() / 2;
            int leftSum = 0;
            int rightSum = 0;

            for (int i = 0; i < n; i++) {
                leftSum += s[i] - '0';
            }

            for (int i = n; i < s.length(); i++) {
                rightSum += s[i] - '0';
            }

            if (leftSum == rightSum) {
                count++;
            }
        }

        return count;
    }
};