#include <vector>
#include <cmath>
#include <queue>

class Solution {
public:
    int minCostConnectPoints(std::vector<std::vector<int>>& points) {
        int n = points.size();
        std::vector<bool> inMST(n, false);
        std::vector<int> minDist(n, 1e9); // stores minimum distance to connect point to MST
        
        minDist[0] = 0;
        int totalCost = 0;
        int edgesConnected = 0;

        while (edgesConnected < n) {
            int currNode = -1;
            int currMinDist = 1e9;

            // Find unvisited vertex with minimum distance to current MST
            for (int i = 0; i < n; ++i) {
                if (!inMST[i] && minDist[i] < currMinDist) {
                    currMinDist = minDist[i];
                    currNode = i;
                }
            }

            // Include selected vertex into MST
            inMST[currNode] = true;
            totalCost += currMinDist;
            edgesConnected++;

            // Update distances of adjacent unvisited vertices
            for (int nextNode = 0; nextNode < n; ++nextNode) {
                if (!inMST[nextNode]) {
                    int dist = std::abs(points[currNode][0] - points[nextNode][0]) + 
                               std::abs(points[currNode][1] - points[nextNode][1]);
                    if (dist < minDist[nextNode]) {
                        minDist[nextNode] = dist;
                    }
                }
            }
        }

        return totalCost;
    }
};