#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        // extendedLength is used to simulate the circular wrap-around.
        // We iterate for (n + k - 1) steps to cover groups that cross the boundary.
        int extendedLength = n + k - 1;
        
        int countGroups = 0;
        int currentAltLength = 1; // current length of the alternating sequence
        int previousColor = colors[0];
        
        // Iterate from 1 to extendedLength - 1, using modulo arithmetic for circular behavior.
        for (int i = 1; i < extendedLength; i++) {
            int currentIndex = i % n;
            // If the current color is the same as the previous one, reset the alternating length.
            if (colors[currentIndex] == previousColor) {
                currentAltLength = 1;
            } else {
                currentAltLength++;
            }
            // If we have reached an alternating sequence of at least k tiles, count it.
            if (currentAltLength >= k) {
                countGroups++;
            }
            previousColor = colors[currentIndex];
        }
        
        return countGroups;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();