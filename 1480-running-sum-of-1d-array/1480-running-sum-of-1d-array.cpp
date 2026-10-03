class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum=0;
        vector<int> vt;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            vt.push_back(sum);
        }
        return vt;
       
        
    }
};