#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool divideArray(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int currentCount = 1;
        int current = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != current) {
                if (currentCount % 2 != 0) return false;
                current = nums[i];
                currentCount = 1;
            } else {
                ++currentCount;
            }
        }
        return true;
    }
};