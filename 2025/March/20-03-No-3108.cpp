#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    vector<int> minAndValue;

    DSU(int n) : parent(n), rank(n, 0), minAndValue(n, INT_MAX) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    void merge(int u, int v, int weight) {
        int rootU = find(u);
        int rootV = find(v);
        
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
                minAndValue[rootU] &= minAndValue[rootV];
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
                minAndValue[rootV] &= minAndValue[rootU];
            } else {
                parent[rootV] = rootU;
                minAndValue[rootU] &= minAndValue[rootV];
                rank[rootU]++;
            }
        }
        // Update the min AND value for the component
        minAndValue[find(u)] &= weight;
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        DSU dsu(n);
        
        // Merge connected components and track min AND value
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dsu.merge(u, v, w);
        }

        vector<int> result;
        for (auto& q : queries) {
            int s = q[0], t = q[1];
            if (dsu.find(s) != dsu.find(t)) {
                result.push_back(-1);
            } else {
                result.push_back(dsu.minAndValue[dsu.find(s)]);
            }
        }
        
        return result;
    }
};
