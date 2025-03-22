#include <bits/stdc++.h>

using namespace std;

class Solution {
    std::vector<bool> m_isVisited;
public:
   bool bfs(int vertex, unordered_map<int, vector<int>> &vertexMap) {
        queue<int> q;
        q.push(vertex);
        m_isVisited[vertex] = true;

        vector<int> component;
        int edgeCount = 0;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            component.push_back(v);

            for (auto adj : vertexMap[v]) {
                edgeCount++;
                if (!m_isVisited[adj]) {
                    m_isVisited[adj] = true;
                    q.push(adj);
                }
            }
        }

        int nodeCount = component.size();
        int expectedEdges = nodeCount * (nodeCount - 1);
        return edgeCount == expectedEdges;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        m_isVisited.resize(n, false);
        std::unordered_map<int, std::vector<int>> vertexMap;
        for (auto edge : edges) {
            vertexMap[edge[0]].emplace_back(edge[1]);
            vertexMap[edge[1]].emplace_back(edge[0]);
        }

        int result = 0;
        while (n--) {
            if (!m_isVisited[n]) {
                if (bfs(n, vertexMap)) {
                    ++result;
                }
            }
        }

        return result;
    }
};