class Solution {
public:
void  solve(vector<vector<int>>& ans,vector<int>temp,vector<int>&nums){
    if(temp.size()==nums.size()){
        ans.push_back(temp);
        return;
    }

    for(int i=0;i<nums.size();i++){
        bool flag=false;
        for(int j=0;j<temp.size();j++){
            if(nums[i]==temp[j]){
                flag=true;
                break;
            }
        }
        if(flag) continue;
        temp.push_back(nums[i]);
        solve(ans,temp,nums);
        temp.pop_back();
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(ans,temp,nums);
        return ans;
    }
};