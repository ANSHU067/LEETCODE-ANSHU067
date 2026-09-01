class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string word;
        int count = 0;

        while (ss >> word) {
            bool canType = true;

            for (char c : word) {
                if (brokenLetters.find(c) != string::npos) {
                    canType = false;
                    break;
                }
            }

            if (canType) {
                count++;
            }
        }

        return count;
    }
};