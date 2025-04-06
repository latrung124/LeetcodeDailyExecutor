#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        using ll = long long;
        ll max = 0;
        size_t size = nums.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                for (int k = j + 1; k < size; ++k) {
                    ll temp = ll(nums[i] - nums[j]) * ll(nums[k]);
                    max = std::max(max, temp);
                }
            }
        }
        return max;
    }
};