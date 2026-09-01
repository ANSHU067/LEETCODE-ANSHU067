class Solution {
public:
    int maxProductDifference(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        int smallest = nums[0];
        int secondSmallest = nums[1];

        int largest = nums[n - 1];
        int secondLargest = nums[n - 2];

        return (largest * secondLargest) -
               (smallest * secondSmallest);
    }
};