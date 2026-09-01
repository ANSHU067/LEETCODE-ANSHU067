class Solution {
public:
    string firstPalindrome(vector<string>& words) {

        for (string word : words) {

            int i = 0;
            int j = word.length() - 1;

            bool palindrome = true;

            while (i < j) {

                if (word[i] != word[j]) {
                    palindrome = false;
                    break;
                }

                i++;
                j--;
            }

            if (palindrome) {
                return word;
            }
        }

        return "";
    }
};