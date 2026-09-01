class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        int monday = 1;
        int daily = 1;

        for (int day = 1; day <= n; day++) {
            total += daily;

            // Next day
            daily++;

            // If next day is Monday
            if (day % 7 == 0) {
                monday++;
                daily = monday;
            }
        }

        return total;
    }
};