class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> st;
        int count = 0;

        for (string word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (st.count(rev)) {
                count++;
            }

            st.insert(word);
        }

        return count;
    }
};