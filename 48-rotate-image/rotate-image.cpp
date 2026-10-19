class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i = 0, j = 0;
        int n = matrix.size();
        while (i < n && j < n) {
            int k = i + 1;
            int l = j + 1;
            while (k < n && l < n) {
                // swap(matrix[k][j], matrix[i][l]);
                int temp = matrix[k][j];
                matrix[k][j] = matrix[i][l];
                matrix[i][l] = temp;
                k++;
                l++;
            }
            i++;
            j++;
        }

        //reverse
        for(int i =0;i<matrix.size();i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

    }
};