class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mp1[256] = {0};
        int mp2[256] = {0};

        for (int i = 0; i < s.length(); i++) {
            char a = s[i];
            char b = t[i];

            if (mp1[a] != 0 && mp1[a] != b)
                return false;

            if (mp2[b] != 0 && mp2[b] != a)
                return false;

            mp1[a] = b;
            mp2[b] = a;
        }

        return true;
    }
};