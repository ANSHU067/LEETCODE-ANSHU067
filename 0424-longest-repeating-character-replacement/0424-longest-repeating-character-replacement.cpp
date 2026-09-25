class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {

            // Add current character
            freq[s[right]]++;

            // Maximum frequency of any character in current window
            maxFreq = max(maxFreq, freq[s[right]]);

            // Number of characters we need to replace
            int replacements = (right - left + 1) - maxFreq;

            // If replacements > k, shrink window
            while (replacements > k) {
                freq[s[left]]--;
                left++;

                replacements = (right - left + 1) - maxFreq;
            }

            // Store maximum valid window length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};