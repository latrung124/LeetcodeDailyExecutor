/*
* File: leetcode.h
* Author: trung.la
* Date: 02-21-2025
* Description: This defines the abstract base class Leetcode that all concrete problems inherit from.
*/

#ifndef LEETCODE_H
#define LEETCODE_H

#include "leetcode_number.h"

#include <string>
#include <vector>

class Leetcode
{
public:
    virtual ~Leetcode() = default;
    const LeetcodeNumberEnum number = LeetcodeNumberEnum::None;

    virtual std::string solve(const std::vector<std::string> &input) = 0;

protected:
    explicit Leetcode(LeetcodeNumberEnum n) : number(n) {}
    Leetcode() = delete;
};

#endif //LEETCODE_H