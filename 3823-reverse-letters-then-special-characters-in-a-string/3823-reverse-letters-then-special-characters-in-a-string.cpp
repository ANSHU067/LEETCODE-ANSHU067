class Solution {
public:
    string reverseByType(string s) {
        string letters;
        string special;

        // Store letters and special characters separately
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                letters.push_back(c);
            }
            else {
                special.push_back(c);
            }
        }

        // Put them back in reverse order
        int l = letters.size() - 1;
        int sp = special.size() - 1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = letters[l--];
            }
            else {
                s[i] = special[sp--];
            }
        }

        return s;
    }
};