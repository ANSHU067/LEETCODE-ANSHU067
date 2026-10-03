class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int count = 0;

            for (int j = 0; j < sorted.size(); j++) {
                if (sorted[j] < nums[i]) {
                    count++;
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};