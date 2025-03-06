#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int a = -1;
        int n = grid.size();
        std::vector<int> caches(n*n + 1, 0);
        for (auto &row : grid) {
            for (auto &it : row) {
                ++caches[it];
                if (caches[it] == 2) {
                    a = it;
                }
            }
        }

        for (int i = 1; i <= caches.size(); ++i) {
            if (caches[i] == 0) {
                return {a, i};
            }
        }

        return {-1, -1};
    }
};