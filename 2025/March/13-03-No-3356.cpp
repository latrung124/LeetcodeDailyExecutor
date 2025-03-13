#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        // Check if the array is already a Zero Array
        if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) {
            return 0;
        }

        // Binary search to find the minimum number of queries needed
        int left = 1, right = q, result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canMakeZero(nums, queries, mid)) {
                result = mid;
                right = mid - 1;  // Try to minimize the number of queries
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

private:
    bool canMakeZero(const vector<int>& nums, const vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);  // Difference array for range updates

        // Apply first k queries efficiently
        for (int i = 0; i < k; i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            int val = queries[i][2];

            diff[left] -= val;   // Subtract value at start index
            if (right + 1 < n) {
                diff[right + 1] += val;  // Restore value after range
            }
        }

        // Apply prefix sum to get final array values
        int current = 0;
        for (int i = 0; i < n; i++) {
            current += diff[i];
            if (nums[i] + current > 0) {
                return false;  // If any value remains > 0, return false
            }
        }

        return true;
    }
};
