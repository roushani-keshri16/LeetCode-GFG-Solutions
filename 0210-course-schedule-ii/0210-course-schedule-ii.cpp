#include <vector>
#include <queue>

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        // Build the adjacency list and compute in-degrees
        // prerequisites[i] = [ai, bi] means bi must be taken before ai (bi -> ai)
        for (const auto& pre : prerequisites) {
            int ai = pre[0];
            int bi = pre[1];
            adj[bi].push_back(ai);
            indegree[ai]++;
        }
        
        queue<int> q;
        // Push all courses with 0 prerequisites into the queue
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topoOrder;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            topoOrder.push_back(curr);
            
            // Reduce in-degree for neighboring courses
            for (int neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If topological order includes all courses, return it; otherwise, a cycle exists.
        if (topoOrder.size() == numCourses) {
            return topoOrder;
        }
        
        return {};
    }
};