class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;

        for (string word : words) {
            if (word.compare(0, pref.length(), pref) == 0) {
                count++;
            }
        }

        return count;
    }
};