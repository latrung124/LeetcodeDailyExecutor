cmake_minimum_required(VERSION 3.10)
project(LeetcodeDailyExecutor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/problem_solver_manager.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/leetcode.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/leetcode_number.h

    ${CMAKE_CURRENT_SOURCE_DIR}/include/problems/three_sum.h
)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/problem_solver_manager.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/problems/three_sum.cpp
)

add_executable(leetcode_daily_solver
    ${SOURCES}
    ${HEADERS}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_include_directories(leetcode_daily_solver PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(COPY ${PROJECT_SOURCE_DIR}/testcase DESTINATION ${CMAKE_BINARY_DIR})