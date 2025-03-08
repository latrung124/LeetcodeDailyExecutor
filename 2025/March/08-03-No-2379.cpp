#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        //count how many in w in first window
        int start = 0;
        int end = k-1;
        int wcount = 0;
        for (int i = start; i <= end; ++i) {
            if (blocks[i] == 'W') ++wcount;
        }

        int temp = wcount;
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i] == 'W') temp++; // new w come into the window
            if (blocks[i - k] == 'W') temp--; // w leaving the window
            wcount = min(wcount, temp);
        }

        return wcount;
    }
};