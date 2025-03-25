#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x_intervals, y_intervals;
        
        // Extract x and y intervals
        for (auto& rect : rectangles) {
            x_intervals.push_back({rect[0], rect[2]});
            y_intervals.push_back({rect[1], rect[3]});
        }
        
        // Check x and y intervals
        return check(x_intervals) || check(y_intervals);
    }

private:
    bool check(vector<vector<int>>& intervals) {
        // Sort intervals by start point
        sort(intervals.begin(), intervals.end());
        
        int sections = 0;
        int max_end = intervals[0][1];
        
        // Single pass through intervals
        for (auto& interval : intervals) {
            // Check if a new section can be formed
            if (max_end <= interval[0]) {
                sections++;
            }
            // Update max end point
            max_end = max(max_end, interval[1]);
        }
        
        // Need at least 2 sections
        return sections >= 2;
    }
};