#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;

        while (true) {
            unordered_set<int> seen;
            bool hasDuplicate = false;

            // Check for duplicates
            for (int num : nums) {
                if (seen.count(num)) {
                    hasDuplicate = true;
                    break;
                }
                seen.insert(num);
            }

            if (!hasDuplicate) break;

            // Remove the first 3 elements (or fewer if not enough left)
            int removeCount = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + removeCount);
            operations++;
        }

        return operations;
    }
};
    