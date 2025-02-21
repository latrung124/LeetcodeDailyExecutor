cmake_minimum_required(VERSION 3.10)
project(LeetcodeDailyExecutor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/problems/*.cpp)

add_executable(leetcode_daily_solver
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/problem_solver_manager.cpp
    ${SOURCES}
)

file(COPY ${PROJECT_SOURCE_DIR}/testcase DESTINATION ${CMAKE_BINARY_DIR})