class Solution {
public:
    bool isValidNode(int newRow, int newCol, int rows, int cols) {
        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols)
            return true;
        return false;
    }
    void solve(vector<vector<char>>& grid, vector<vector<int>>& vis, int i,
               int j, int rows, int cols) {
        vis[i][j] = 1;

        vector<int> adjacentRows = {-1, 0, 1, 0};
        vector<int> adjacentCols = {0, -1, 0, 1};

        for (int k = 0; k < 4; k++) {
            // validate adjacent nodes
            int newRow = i + adjacentRows[k];
            int newCol = j + adjacentCols[k];

            if (isValidNode(newRow, newCol, rows, cols) &&
                grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                solve(grid, vis, newRow, newCol, rows, cols);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // should be 1 and not vis
                if (grid[i][j] == '1' && !vis[i][j]) {
                    // go through from all its adjacent nodes
                    solve(grid, vis, i, j, row, col);
                    ans++;
                }
            }
        }
        return ans;
    }
};