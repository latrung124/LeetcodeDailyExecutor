/*
* File: problem_solver_manager.h
* Author: trung.la
* Date: 02-21-2025
* Description: This declares the ProblemSolverManager to manage and run problems.
*/

#ifndef PROBLEM_SOLVER_MANAGER_H
#define PROBLEM_SOLVER_MANAGER_H

#include <memory>
#include <unordered_map>
#include <string>

class Leetcode;
enum class LeetcodeNumberEnum;

class ProblemSolverManager
{
private:
    std::string m_testcaseDir;
    std::unordered_map<LeetcodeNumberEnum, std::unique_ptr<Leetcode>> problemMap;

public:
    ProblemSolverManager(const std::string &dir);

    void addProblem(std::unique_ptr<Leetcode> problem);
    void runAll();
    void runTestsForProblem(const LeetcodeNumberEnum &num);
};

#endif //PROBLEM_SOLVER_MANAGER_H