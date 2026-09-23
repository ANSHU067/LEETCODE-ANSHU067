class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int wordLength = words[0].length();
        int totalWords = words.size();
        int totalLength = wordLength * totalWords;

        if (s.length() < totalLength) {
            return ans;
        }

        // Required frequency
        unordered_map<string, int> mp;

        for (string word : words) {
            mp[word]++;
        }

        // We need to check wordLength different starting positions
        for (int start = 0; start < wordLength; start++) {

            int left = start;
            int right = start;

            int count = 0;

            unordered_map<string, int> temp;

            while (right + wordLength <= s.length()) {

                string current = s.substr(right, wordLength);
                right += wordLength;

                // Current word doesn't exist
                if (mp.find(current) == mp.end()) {

                    temp.clear();
                    count = 0;
                    left = right;

                    continue;
                }

                // Add current word
                temp[current]++;
                count++;

                // Too many occurrences of current word
                while (temp[current] > mp[current]) {

                    string removeWord = s.substr(left, wordLength);

                    temp[removeWord]--;
                    left += wordLength;
                    count--;
                }

                // We have exactly all words
                if (count == totalWords) {

                    ans.push_back(left);

                    // Move left pointer to look for next answer
                    string removeWord = s.substr(left, wordLength);

                    temp[removeWord]--;
                    left += wordLength;
                    count--;
                }
            }
        }

        return ans;
    }
};