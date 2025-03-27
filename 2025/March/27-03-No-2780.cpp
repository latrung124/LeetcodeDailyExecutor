#include <bits/stdc++.h>

class Solution {
public:
    int minimumIndex(std::vector<int> &nums) {
        std::unordered_map<int, int> freq;
        int size = nums.size();

        // Step 1: Find the dominant element
        for (int num : nums) {
            freq[num]++;
        }

        int dominant = -1;
        for (auto &[num, count] : freq) {
            if (count * 2 > size) {
                dominant = num;
                break;
            }
        }

        if (dominant == -1) return -1; // No valid dominant element found

        // Step 2: Check valid split
        int left_count = 0;
        for (int i = 0; i < size - 1; ++i) {
            if (nums[i] == dominant) left_count++;

            int right_count = freq[dominant] - left_count;

            if (left_count * 2 > (i + 1) && right_count * 2 > (size - (i + 1))) {
                return i;
            }
        }

        return -1;
    }
};
