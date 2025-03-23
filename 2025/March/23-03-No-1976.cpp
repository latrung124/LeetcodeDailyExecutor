#include <vector>
#include <queue>
#include <limits>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Define mod constant.
        const int MOD = 1e9 + 7;
        // Build graph: each road is bidirectional.
        vector<vector<pair<int, int>>> graph(n);
        for (auto &r : roads) {
            int u = r[0], v = r[1], time = r[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        
        // dist[i]: shortest time from node 0 to i.
        // ways[i]: number of ways to achieve that shortest time.
        vector<long long> dist(n, numeric_limits<long long>::max());
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        
        // Min-heap: (distance, node)
        using pii = pair<long long, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [currDist, u] = pq.top();
            pq.pop();
            // If we have a stale entry, skip.
            if (currDist > dist[u])
                continue;
            for (auto &[v, w] : graph[u]) {
                long long newDist = currDist + w;
                if (newDist < dist[v]) {
                    // Found a shorter path to v.
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.push({newDist, v});
                } else if (newDist == dist[v]) {
                    // Found another shortest path to v.
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        
        return (int)ways[n-1];
    }
};
