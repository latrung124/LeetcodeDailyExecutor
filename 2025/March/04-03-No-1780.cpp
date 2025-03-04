#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int k = 16;
        while (k >= 0 && n > 0) {
            for (int i = k; i >= 0; --i) {
                int temp = std::pow(3, k);
                if (temp < n) {
                    n -= temp;
                    k = i - 1;
                } else if (temp == n) {
                    return true;
                } else {
                    --k;
                }
            }
        }

        return k == 0;
    }
};