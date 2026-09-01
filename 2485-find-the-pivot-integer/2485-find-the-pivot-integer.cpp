class Solution {
public:
    int pivotInteger(int n) {

        int total = 0;

        // Sum from 1 to n
        for (int i = 1; i <= n; i++) {
            total += i;
        }

        int leftSum = 0;

        for (int x = 1; x <= n; x++) {

            leftSum += x;

            int rightSum = total - leftSum + x;

            if (leftSum == rightSum) {
                return x;
            }
        }

        return -1;
    }
};