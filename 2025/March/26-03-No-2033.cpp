#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> values;
        int m = grid.size(), n = grid[0].size();
        
        // Flatten the grid into a 1D array
        for (const auto& row : grid) {
            for (int num : row) {
                values.push_back(num);
            }
        }

        // Check if all numbers have the same remainder when divided by x
        int remainder = values[0] % x;
        for (int num : values) {
            if (num % x != remainder) return -1;
        }

        // Sort the values and find the median
        sort(values.begin(), values.end());
        int median = values[values.size() / 2];

        // Compute the total number of operations to make all elements equal to median
        int operations = 0;
        for (int num : values) {
            operations += abs(num - median) / x;
        }

        return operations;
    }
};
