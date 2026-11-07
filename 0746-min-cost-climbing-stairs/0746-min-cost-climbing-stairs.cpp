
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = 0;
        int prev1 = 0;

        for (int i = 0; i < cost.size(); i++) {
            int curr = cost[i] + min(prev1, prev2);

            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};
