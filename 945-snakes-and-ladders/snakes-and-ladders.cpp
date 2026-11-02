class Solution {
public:

    pair<int,int>getCord(int point, int n){
       int row = 0;
       int quotient = point/n;
       int reminder = point%n;
        // for row
       if(point<=n ){
        row = n-1;
       }
       else {
        if(reminder==0) {
            
            row = n-quotient;
        }
        else  row = n-1-quotient;
       }

        int col = 0;
       // for find the col
       if(reminder==0){
        if(quotient%2==0) col = 0;
        else col = n-1;
       }
       else {
        if(quotient%2==0) col = reminder-1;
        else col = n-reminder;
       }
       return make_pair(row,col);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        // now we do bfs on graph
        int n = board.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));

        queue<int> q;
        int steps = 0;

        if (board[n - 1][0] != -1) {
            q.push(board[n - 1][0]);
            pair<int, int> cord = getCord(board[n - 1][0], n);
            vis[cord.first][cord.second] = 1;
        } else {
            q.push(1);
            vis[n - 1][0] = 1;
        }

        while (!q.empty()) {
            int size = q.size();
            steps++;
            while (size--) {
                int currentPos = q.front();
                q.pop();
                if (currentPos == n * n)
                    return steps-1;
                // from here im able to going to next 6 position
                for (int i = 1; i <= 6; i++) {
                    int newPos = currentPos + i;
                    if (newPos <= n * n) {
                        // we shoould find the cord,
                        pair<int, int> newCord = getCord(newPos, n);
                        // and should be no visited then push
                        if (!vis[newCord.first][newCord.second]) {
                            if (board[newCord.first][newCord.second] != -1) {
                                q.push(board[newCord.first][newCord.second]);
                                // vis[newCord.first][newCord.second] = 1;
                            } else {
                                q.push(newPos);
                            }
                            vis[newCord.first][newCord.second] = 1;
                        }
                        // if its cord value is -1 then push the newPos
                        // otherwise push its actual val if its not visited
                    }
                }
            }
        }
        return -1;

    }
};