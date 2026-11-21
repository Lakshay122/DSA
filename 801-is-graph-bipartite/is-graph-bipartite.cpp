class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();

        vector<int> vis(nodes, -1);
        queue<int> q;
        for (int i = 0; i < nodes; i++) {
            if (vis[i] == -1) {
                q.push(i);
                vis[i] = 0;
                while (!q.empty()) {
                    int size = q.size();

                    while (size--) {
                        int node = q.front();
                        q.pop();

                        int adjacentSize = graph[node].size();

                        for (int i = 0; i < adjacentSize; i++) {
                            // here move its adjacent nodes;
                            int adjacentNode = graph[node][i];
                            int currentNodeColor = vis[node];          // 1
                            int adjacentNodeColor = vis[adjacentNode]; //-1
                            // cout<<adjacentNode<<"÷ "<<currentNodeColor<<"
                            // "<<adjacentNodeColor<<endl;
                            if (adjacentNodeColor == -1) {
                                vis[adjacentNode] = !currentNodeColor;
                                // cout<<vis[adjacentNode]<<endl;
                                q.push(adjacentNode);
                            } else if (currentNodeColor == adjacentNodeColor)
                                return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};