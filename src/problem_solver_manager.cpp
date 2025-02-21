/*
* File: problem_solver_manager.cpp
* Author: trung.la
* Date: 02-21-2025
* Description: This declares the ProblemSolverManager to manage and run problems.
*/

#include "problem_solver_manager.h"
#include "leetcode.h"

#include <iostream>

ProblemSolverManager::ProblemSolverManager(const std::string &dir)
    : m_testcaseDir(dir)
{
}

void ProblemSolverManager::addProblem(std::unique_ptr<Leetcode> problem) {
    problemMap[problem->number] = std::move(problem);
}

void ProblemSolverManager::runAll() {
    for (const auto& [num, problem] : problemMap) {
        std::cout << "Running " << static_cast<uint16_t>(num) << ": ";
        std::vector<std::string> dummyInput = {"1,2,-3"}; // Replace with actual test case loading
        std::cout << problem->solve(dummyInput) << "\n";
    }
}

void ProblemSolverManager::runTestsForProblem(const LeetcodeNumberEnum &num)
{
    auto it = problemMap.find(num);
}