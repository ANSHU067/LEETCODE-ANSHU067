class Solution {
public:
void print(vector<int>& nums,int idx,vector<int>&ans,vector<vector<int>>& allsub){
    if(idx==nums.size()){
        allsub.push_back(ans);
        // for(int x:nums){
        //     cout<<x;
        // }
        return ;
    }
    ans.push_back(nums[idx]);
    print(nums,idx+1,ans,allsub);
    ans.pop_back();
    print(nums,idx+1,ans,allsub);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>allsub;
        print(nums,0,ans,allsub);
        return allsub;
    }
};