#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        std::vector<int> smallers;
        std::vector<int> biggers;
        std::vector<int> result;
        for (auto num : nums) {
            if (num < pivot)
                smallers.push_back(num);
            else if (num > pivot)
                biggers.push_back(num);
            else
                result.push_back(num);
        }
        result.insert(result.begin(), smallers.begin(), smallers.end());
        result.insert(result.end(), biggers.begin(), biggers.end());
        return result;
    }
};