/*
* File: three_sum.cpp
* Author: trung.la
* Date: 02-21-2025
* Description: This defines the three sum problem that inherites leetcode class.
*/

#include "problems/three_sum.h"

#include <sstream>

ThreeSumProblem::ThreeSumProblem()
    : Leetcode(LeetcodeNumberEnum::No_15)
    , solutionUPtr(std::make_unique<ThreeSumProblem::Solution>())
{
}

ThreeSumProblem::~ThreeSumProblem()
{
}

std::string ThreeSumProblem::solve(const std::vector<std::string>& input) {
    if (input.size() != 1) return "Invalid input";
    try {
        std::vector<int> nums;
        std::stringstream ss(input[0]);
        std::string token;
        while (std::getline(ss, token, ',')) {
            nums.push_back(std::stoi(token));
        }
        auto result = solutionUPtr->threeSum(nums);
        std::string serialized;
        for (const auto& triplet : result) {
            serialized += "(" + std::to_string(triplet[0]) + "," +
                          std::to_string(triplet[1]) + "," +
                          std::to_string(triplet[2]) + ")";
        }
        return serialized.empty() ? "No solution" : serialized;
    } catch (const std::exception& e) {
        return "Invalid input";
    }
}