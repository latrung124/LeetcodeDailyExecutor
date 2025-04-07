#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Step 1: Calculate total sum of the array
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // Step 2: If the sum is odd, we can't split it equally
        if (sum % 2 != 0) return false;

        // Step 3: The target for each subset should be half the sum
        int target = sum / 2;

        // Step 4: Create a DP array of size (target + 1)
        // dp[i] means whether it's possible to form sum i using some subset of nums
        vector<bool> dp(target + 1, false);

        // Step 5: It's always possible to form sum 0 using the empty subset
        dp[0] = true;

        // Step 6: For each number in the array
        for (int num : nums) {
            // Step 7: Traverse dp array **backwards** to avoid reusing the same number
            for (int i = target; i >= num; --i) {
                // If dp[i - num] is true, then dp[i] can be true too
                dp[i] = dp[i] || dp[i - num];
            }
        }

        // Step 8: If dp[target] is true, we can partition the array into two equal sum subsets
        return dp[target];
    }
};
