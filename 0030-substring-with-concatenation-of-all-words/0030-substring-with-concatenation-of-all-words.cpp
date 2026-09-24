class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> answer;

        int wordLength = words[0].length();
        int totalWords = words.size();
        int totalLength = wordLength * totalWords;

        unordered_map<string, int> requiredWords;

        // Store required frequency of every word
        for (string word : words) {
            requiredWords[word]++;
        }

        // Try every possible starting position
        for (int start = 0; start < wordLength; start++) {

            int left = start;
            int right = start;

            int wordsInWindow = 0;

            unordered_map<string, int> currentWords;

            while (right + wordLength <= s.length()) {

                // Take one word from the string
                string currentWord = s.substr(right, wordLength);
                right += wordLength;

                // If this word is not required
                if (requiredWords.find(currentWord) == requiredWords.end()) {

                    currentWords.clear();
                    wordsInWindow = 0;
                    left = right;

                }
                else {

                    currentWords[currentWord]++;
                    wordsInWindow++;

                    // Too many copies of this word
                    while (currentWords[currentWord] >
                           requiredWords[currentWord]) {

                        string leftWord = s.substr(left, wordLength);

                        currentWords[leftWord]--;
                        left += wordLength;
                        wordsInWindow--;
                    }

                    // We have exactly all required words
                    if (wordsInWindow == totalWords) {

                        answer.push_back(left);

                        // Move left forward for the next possible answer
                        string leftWord = s.substr(left, wordLength);

                        currentWords[leftWord]--;
                        left += wordLength;
                        wordsInWindow--;
                    }
                }
            }
        }

        return answer;
    }
};