class Solution {
private:
    void dfs(int node, int parent, int &timer, vector<int>& tin, vector<int>& low, 
             vector<int> adj[], vector<vector<int>>& bridges, vector<int>& vis) {
        vis[node] = 1;
        tin[node] = low[node] = ++timer;
        
        for (auto it : adj[node]) {
            if (it == parent) continue;
            
            if (vis[it]) {
                // Back-edge: update low of current node
                low[node] = min(low[node], tin[it]);
            } else {
                // Forward edge: visit unvisited neighbor
                dfs(it, node, timer, tin, low, adj, bridges, vis);
                low[node] = min(low[node], low[it]);
                
                // Check if the edge can reach back to an ancestor of 'node'
                if (low[it] > tin[node]) {
                    bridges.push_back({node, it});
                }
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Step 1: Build the adjacency list
        vector<int> adj[n];
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        vector<int> vis(n, 0);
        vector<vector<int>> bridges;
        int timer = 0;
        
        // Step 2: Run DFS starting from node 0 (assuming graph is connected)
        dfs(0, -1, timer, tin, low, adj, bridges, vis);
        
        return bridges;
    }
};