class Solution {
private:
    int robLinear(const vector<int>& nums, int start, int end) {
        int prev2 = 0; // represents dp[i-2]
        int prev1 = 0; // represents dp[i-1]
        
        for (int i = start; i <= end; ++i) {
            int current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Base cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        // Option 1: Include first house, exclude last house (0 to n-2)
        // Option 2: Exclude first house, include last house (1 to n-1)
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }
};