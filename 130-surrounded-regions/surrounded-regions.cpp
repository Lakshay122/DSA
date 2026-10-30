class Solution {
public:
    bool isValidNode(int newRow, int newCol, int rows, int cols) {
        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols)
            return true;
        return false;
    }
    void adjacentNodes(vector<vector<char>>& board, int i, int j, int rows,
                       int cols) {
        board[i][j] = 'A';
        cout<<i<<" "<<j<<endl;
        vector<int> adjacentRows = {-1, 0, 1, 0};
        vector<int> adjacentCols = {0, -1, 0, 1};

        for (int k = 0; k < 4; k++) {
            // validate adjacent nodes
            int newRow = i + adjacentRows[k];
            int newCol = j + adjacentCols[k];

            if (isValidNode(newRow, newCol, rows, cols) &&
                board[newRow][newCol] == 'O') {
                adjacentNodes(board, newRow, newCol, rows, cols);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        // fetch the zeros only on edge
        // then make -1 on that all adjaent ndoe bcs tht always menas

        // question how to move only from edge as code
        // row ={0}
        // col= {n-1}

        int rows = board.size();
        int cols = board[0].size();
        int top = 0;
        int right = cols - 1;
        int bottom = rows - 1;
        int left = 0;

        for (int i = 0; i <= right; i++) {

            if (board[top][i] == 'O') {
                adjacentNodes(board, top, i, rows, cols);
            }
        }
        top++;
        if(top<=bottom){

        for (int i = top; i <= bottom; i++) {

            if (board[i][right] == 'O') {
                adjacentNodes(board, i, right, rows, cols);
            }
        }
        right--;
        cout<<"bottom"<<bottom <<" "<<top<<" "<<right<<" "<<left<<endl;
        for (int i = right; i >= left; i--) {

            if (board[bottom][i] == 'O') {
                cout<<bottom<<" "<<i<<endl;
                adjacentNodes(board, bottom, i, rows, cols);
            }
        }
        bottom--;
        for (int i = bottom; i >= top; i--) {

            if (board[i][left] == 'O') {
                adjacentNodes(board, i, left, rows, cols);
            }
        }
        left++;

        }
        for (int i = 0;i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout<<board[i][j]<<endl;
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
                else if(board[i][j]=='O') board[i][j] = 'X';
            }
        }
    }
};