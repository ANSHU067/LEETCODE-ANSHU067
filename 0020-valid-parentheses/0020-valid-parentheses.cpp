class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        unordered_map<char, char> match = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char ch : s) {

            // If it's a closing bracket
            if (match.count(ch)) {
                if (!st.empty() && st.top() == match[ch]) {
                    st.pop();
                } else {
                    return false;
                }
            } 
            else {
                st.push(ch);
            }
        }

        return st.empty();
    }
};