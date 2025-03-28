#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int k = queries.size();
        
        // Create array of pairs {query_value, index} to sort queries while preserving original order
        vector<pair<int, int>> queryWithIndex(k);
        for(int i = 0; i < k; ++i) {
            queryWithIndex[i] = {queries[i], i};
        }
        sort(queryWithIndex.begin(), queryWithIndex.end());
        
        // Directions for adjacent cells: up, right, down, left
        int dirs[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        
        // Priority queue to process cells by smallest value first
        priority_queue<pair<int, pair<int,int>>, 
                    vector<pair<int, pair<int,int>>>, 
                    greater<>> pq;
        
        // Visited array
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Result array
        vector<int> answer(k);
        
        // Start from top-left
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        int points = 0;
        
        // Process each query in ascending order
        for(int i = 0; i < k; ++i) {
            int currQuery = queryWithIndex[i].first;
            int queryIdx = queryWithIndex[i].second;
            
            // Process all cells we can reach until we hit a value >= currQuery
            while(!pq.empty() && pq.top().first < currQuery) {
                int val = pq.top().first;
                int r = pq.top().second.first;
                int c = pq.top().second.second;
                pq.pop();
                points++;
                
                // Check all 4 adjacent cells
                for(auto dir : dirs) {
                    int newR = r + dir[0];
                    int newC = c + dir[1];
                    
                    // Check if new position is valid and not visited
                    if(newR >= 0 && newR < m && newC >= 0 && newC < n && 
                    !visited[newR][newC]) {
                        visited[newR][newC] = true;
                        pq.push({grid[newR][newC], {newR, newC}});
                    }
                }
            }
            
            // Assign the maximum points possible for this query
            answer[queryIdx] = points;
        }
        
        return answer;
    }
};