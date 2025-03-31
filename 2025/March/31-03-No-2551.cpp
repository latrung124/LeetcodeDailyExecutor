#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<long long> pairSums;
        
        // Step 1: Compute sums of adjacent elements
        for (int i = 0; i < n - 1; i++) {
            pairSums.push_back(weights[i] + weights[i + 1]);
        }

        // Step 2: Sort the adjacent sums
        sort(pairSums.begin(), pairSums.end());

        long long minSum = 0, maxSum = 0;
        
        // Step 3: Compute the max and min sum using (k-1) largest/smallest pairs
        for (int i = 0; i < k - 1; i++) {
            minSum += pairSums[i];                      // Smallest pairs
            maxSum += pairSums[n - 2 - i];              // Largest pairs
        }

        // Step 4: Compute the difference
        return maxSum - minSum;
    }
};
