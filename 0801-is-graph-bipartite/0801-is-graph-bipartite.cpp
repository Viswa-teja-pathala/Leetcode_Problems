class Solution {
public:
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = col;  // Color the current node

        // Traverse all adjacent nodes
        for (auto it : graph[node]) {
            if (color[it] == -1) {
                // If the adjacent node has not been colored, color it with the opposite color
                if (!dfs(it, !col, color, graph)) {
                    return false;
                }
            } else if (color[it] == col) {
                // If the adjacent node has the same color, the graph is not bipartite
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // Initialize all nodes with no color

        // Check each component of the graph
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                // If the node has not been colored, start a DFS from it
                if (!dfs(i, 0, color, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
};
