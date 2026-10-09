class Solution {
public:
int dp[101];
    int rober(vector<int>& nums, int idx) {
        if (idx >= nums.size()) {
            return 0;
        }
        if(dp[idx]!=-1)return dp[idx];

        int ans1 = nums[idx] + rober(nums, idx + 2);
        int ans2 = rober(nums, idx + 1);
        

        return dp[idx]=max(ans1, ans2);
      
    }

    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return rober(nums, 0);

    }
};