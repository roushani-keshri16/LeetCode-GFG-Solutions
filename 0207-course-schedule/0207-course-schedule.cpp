class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        // Build adjacency list and in-degree array
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            inDegree[course]++;
        }
        
        // Push all courses with 0 in-degree into the queue
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        int processedCourses = 0;
        
        // BFS traversal
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            processedCourses++;
            
            for (int neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If we processed all courses, there are no cycles
        return processedCourses == numCourses;
    }
};