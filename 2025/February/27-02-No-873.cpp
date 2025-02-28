/*
* Explaination
* Approach:
* 1. Initialization:
* n is the size of the input array arr.
* dp[i][j] is a 2D vector where dp[i][j] represents the length of the longest Fibonacci-like subsequence ending with arr[i] and arr[j].
* Initially, all values are set to 2 because any pair of numbers can form a Fibonacci-like subsequence of length 2.
* index is an unordered map that stores the value-to-index mapping of the array arr. This allows for quick lookup of the index of a value.
* 2. Filling the DP Table:
* The outer loop iterates over all possible ending indices j of the subsequence.
* The inner loop iterates over all possible starting indices i (where i < j).
* For each pair (i, j), the code calculates the candidate previous number kVal in the Fibonacci-like sequence as arr[j] - arr[i].
* If kVal exists in the array and its index k is less than i, then (k, i, j) forms a valid Fibonacci-like subsequence.
* The length of this subsequence is updated as dp[i][j] = dp[k][i] + 1.
* The maximum length found so far is stored in ans.
* 3. Result:
* If the maximum length ans is at least 3, it is returned; otherwise, 0 is returned (since a Fibonacci-like subsequence must have at least 3 elements).
*
* Complexity Analysis:
* Time Complexity: O(n^2)
* Space Complexity: O(n^2)
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        // dp[i][j] : length of Fibonacci-like subsequence ending with arr[i] and arr[j]
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 2));
        std::unordered_map<int, int> index;
        for (int i = 0; i < n; ++i) {
            index[arr[i]] = i;
        }
        
        int ans = 0;
        // Iterate over all pairs (i, j) with i < j
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                int kVal = arr[j] - arr[i];  // Candidate previous number in Fibonacci-like sequence
                // To form a valid Fibonacci sequence, we need arr[k] = arr[j] - arr[i] and k < i.
                if (kVal < arr[i] && index.find(kVal) != index.end()) {
                    int k = index[kVal];
                    dp[i][j] = dp[k][i] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans >= 3 ? ans : 0;
    }
};