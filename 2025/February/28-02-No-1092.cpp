/*
* Explaination
*
* Approach:
* 1. Longest Common Subsequence (LCS): Compute the LCS of the two input strings using
* dynamic programming. The LCS helps in identifying the common characters that can be merged
* once in the supersequence(SCS).
* 2. Backtracking to construct the SCS: Using the DP table built for LCS, backtrack from the end of both strings to the start
* constructing the SCS by combining characters from both strings. When characters match (part of LCS), they are added once.
* For non-matching characters , the direction (up or left) in the DP table with a higher LCS value is chosen to ensure the shortest path.
* 
* Complexity Analysis:
* Time Complexity: O(m*n), where m and n are the lengths of the input strings str1 and str2.
* The DP table of size (m+1) x (n+1) is filled in O(m*n) time.
* Space Complexity: O(m*n), where m and n are the lengths of the input strings str1 and str2.
* The DP table of size (m+1) x (n+1) is used.
*/

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Build the DP table for LCS
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        string res;
        int i = m, j = n;
        
        // Backtrack to build the result
        while (i > 0 && j > 0) {
            if (str1[i-1] == str2[j-1]) {
                res.push_back(str1[i-1]);
                --i;
                --j;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                res.push_back(str1[i-1]);
                --i;
            } else {
                res.push_back(str2[j-1]);
                --j;
            }
        }
        
        // Add remaining characters from str1 or str2
        while (i > 0) {
            res.push_back(str1[i-1]);
            --i;
        }
        while (j > 0) {
            res.push_back(str2[j-1]);
            --j;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

// Steps:

// 1. LCS Calculation: The DP table is constructed where dp[i][j] represents the length of the LCS of the substrings str1[0..i-1] and str2[0..j-1].
// This helps in identifying common subsequences efficiently.

// 2. Backtracking for SCS: Starting from the end of both strings, we backtrack using the DP table to construct the SCS.
// If characters match, they are added once. If not, the direction with a higher LCS value is chosen to ensure the shortest path.

// 3. Handling Remaining Characters: After processing the LCS, any remaining characters from either string are appended
// to ensure all characters are included in the supersequence.