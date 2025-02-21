/*
* File: three_sum.h
* Author: trung.la
* Date: 02-21-2025
* Description: This defines the three sum problem that inherites leetcode class.
*/

#ifndef THREE_SUM_H
#define THREE_SUM_H

#include "leetcode.h"

#include <memory>

class Solution;

class ThreeSumProblem : public Leetcode
{
private:
    class Solution
    {
    public:
        Solution() = default;
        ~Solution() = default;
        std::vector<std::vector<int>> threeSum(std::vector<int>& nums) { return {}; }
    };

    std::unique_ptr<Solution> solutionUPtr = nullptr;
public:
    ThreeSumProblem();
    ~ThreeSumProblem();
    std::string solve(const std::vector<std::string> &input) override;
};

#endif //THREE_SUM_H