#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestNiceSubarray(std::vector<int>& nums) {
        int left = 0, bitwiseOR = 0, maxLength = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while ((bitwiseOR & nums[right]) != 0) {
                bitwiseOR ^= nums[left];  // Remove nums[left] from the window
                left++;
            }
            bitwiseOR |= nums[right];  // Add nums[right] to the window
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};