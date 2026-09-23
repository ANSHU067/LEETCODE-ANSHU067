class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0;
        int left = 0;
        int right = 0;
        int zerocount = 0;
        int maxcount = 0;

        while (right < nums.size()) {

            // Add current element to window
            if (nums[right] == 0) {
                zerocount++;
            }

            // Shrink window if zeros exceed k
            while (zerocount > k) {
                if (nums[left] == 0) {
                    zerocount--;
                }
                left++;
            }

            // Current window length
            count = right - left + 1;

            // Update maximum
            maxcount = max(count, maxcount);

            right++;
        }

        return maxcount;
    }
};