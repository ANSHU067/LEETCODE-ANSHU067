class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        unordered_map<string, int> mp;
        set<string> st;

        // banned words
        for (string s : banned) {
            st.insert(s);
        }

        // lowercase + punctuation remove
        for (char &c : paragraph) {
            if (ispunct(c))
                c = ' ';
            else
                c = tolower(c);
        }

        // words
        string x;
        stringstream ss(paragraph);

        while (ss >> x) {
            mp[x]++;
        }

        int max_freq = 0;
        string ans = "";

        for (auto &p : mp) {
            if (st.find(p.first) == st.end() && p.second > max_freq) {
                max_freq = p.second;
                ans = p.first;
            }
        }

        return ans;
    }
};