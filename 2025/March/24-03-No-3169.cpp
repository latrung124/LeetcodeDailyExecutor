#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days; // If no meetings, all days are available
        
        // Step 1: Sort meetings by start time
        sort(meetings.begin(), meetings.end());
        
        // Step 2: Merge overlapping meetings
        vector<pair<int, int>> merged;
        int start = meetings[0][0], end = meetings[0][1];
        
        for (int i = 1; i < meetings.size(); ++i) {
            if (meetings[i][0] <= end) { // Overlapping interval, extend the end time
                end = max(end, meetings[i][1]);
            } else {
                merged.push_back({start, end});
                start = meetings[i][0];
                end = meetings[i][1];
            }
        }
        merged.push_back({start, end});
        
        // Step 3: Compute the number of free days
        int freeDays = merged[0].first - 1; // Days before the first meeting
        for (int i = 1; i < merged.size(); ++i) {
            freeDays += merged[i].first - merged[i - 1].second - 1; // Gaps between meetings
        }
        freeDays += days - merged.back().second; // Days after the last meeting
        
        return freeDays;        
    }
};