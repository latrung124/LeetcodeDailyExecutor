#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        std::vector<int> result;
        int zeroCount = 0;
        size_t size = nums.size();
        for (int i = 0; i < size - 1; ++i) {
            if (nums[i] != 0 && nums[i] == nums[i+1]) {
                result.emplace_back(nums[i]*2);
                nums[i+1] = 0;
            } else {
                if (nums[i] != 0)
                    result.emplace_back(nums[i]);
                else
                    ++zeroCount;
            }
        }
        result.emplace_back(nums[size - 1]);
        while (zeroCount--) {
            result.emplace_back(0);
        }
        return result;
    }
};