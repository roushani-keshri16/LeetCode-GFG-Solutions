#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 1. Build adjacency list: adj[u] = {{v, price}, ...}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // 2. Queue for BFS storing {stops, {current_node, current_cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        // 3. Distance array initialized to infinity
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // 4. BFS Traversal
        while (!q.empty()) {
            auto auto_front = q.front();
            q.pop();

            int stops = auto_front.first;
            int node = auto_front.second.first;
            int cost = auto_front.second.second;

            // If stops exceed k, stop expanding from this path
            if (stops > k) continue;

            for (const auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int price = neighbor.second;

                // Relaxation step
                if (cost + price < dist[nextNode] && stops <= k) {
                    dist[nextNode] = cost + price;
                    q.push({stops + 1, {nextNode, dist[nextNode]}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};