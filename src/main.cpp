/*
* File: main.cpp
* Author: trung.la
* Date: 02-21-2025
* Description: This is main source file.
*/

#include "problem_solver_manager.h"
#include "problems/three_sum.h"

#include <iostream>

int main()
{
    std::cout << "Hello, World! \n";
    ProblemSolverManager manager("testcase");
    manager.addProblem(std::make_unique<ThreeSumProblem>());
    manager.runAll();
    return 0;
}