#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximumCount(const std::vector<int> &nums) {
        int n = nums.size();

        int firstZero = std::lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int firstPositive = std::lower_bound(nums.begin(), nums.end(), 1) - nums.begin();

        int negCount = firstZero;
        int posCount = n - firstPositive;

        return std::max(negCount, posCount);
    }
};