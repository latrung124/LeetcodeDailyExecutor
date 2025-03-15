#include <bits/stdc++.h>

class Solution
{
public:
    bool canRobWithCapability(std::vector<int> const &nums, int k, int cap) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= cap) {
                if (!--k) return true;
                ++i;
            }
        }
        return false;
    }

    int minCapability(std::vector<int> &nums, int k) {
        if (nums.size() == 1) return nums[0];

        int low = *std::min_element(nums.begin(), nums.end());
        int high = *std::max_element(nums.begin(), nums.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canRobWithCapability(nums, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};