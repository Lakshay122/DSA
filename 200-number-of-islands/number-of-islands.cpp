class Solution {
public:
    bool isValidPoints(int newRow, int newColumn, int totalRows,
                       int totalColumns) {
        if (newRow >= 0 && newRow < totalRows && newColumn >= 0 &&
            newColumn < totalColumns)
            return true;
        return false;
    }

    void solve(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i,
               int j, int totalRows, int totalColumns) {
        visited[i][j] = true;
        vector<int> rows = {-1, 0, 1, 0};
        vector<int> column = {0, -1, 0, 1};
        for (int k = 0; k < 4; k++) {
            int newRow = i + rows[k];
            int newColumn = j + column[k];

            if (isValidPoints(newRow, newColumn, totalRows, totalColumns) &&
                visited[newRow][newColumn] == false &&
                grid[newRow][newColumn] == '1') {
                // call for that adjacent
                // return;
                solve(grid, visited, newRow, newColumn, totalRows, totalColumns);
            }
        }
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        // steps is something like
        // we are going to start from 1 node whos vlaue is 1 then find its
        // adjancent node whose value is 1 and marked as visited
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == false && grid[i][j] == '1') {
                    solve(grid, visited, i, j, m, n);
                    ans += 1;
                }
            }
        }
        return ans;
    }
};