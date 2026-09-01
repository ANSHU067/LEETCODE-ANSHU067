class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> answer;
        
        int minCost = INT_MAX;

        for (int i = 0; i < cost.size(); i++) {
            minCost = min(minCost, cost[i]);
            answer.push_back(minCost);
        }

        return answer;
    }
};