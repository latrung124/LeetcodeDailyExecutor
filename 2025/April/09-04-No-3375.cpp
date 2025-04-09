#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Check for invalid case
        for (int num : nums) {
            if (num < k) return -1;  // can't increase
        }

        // Use a set to count distinct values > k
        unordered_set<int> greaterThanK;

        for (int num : nums) {
            if (num > k) {
                greaterThanK.insert(num);
            }
        }

        return greaterThanK.size(); // each one will need one operation
    }
};
