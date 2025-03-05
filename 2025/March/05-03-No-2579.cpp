#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        long long result = 1;
        if (n == 1) return result;
        while (n-- >= 1) {
            result += 4 * n;
        }

        return result;
    }
};