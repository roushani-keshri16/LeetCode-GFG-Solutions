class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0, total_cost = 0;
        int current_tank = 0, start = 0;

        for (int i = 0; i < gas.size(); ++i) {
            total_gas += gas[i];
            total_cost += cost[i];
            current_tank += gas[i] - cost[i];

            // If the tank goes negative, we can't start from the current 'start'
            if (current_tank < 0) {
                start = i + 1;
                current_tank = 0;
            }
        }

        return (total_gas < total_cost) ? -1 : start;
    }
};