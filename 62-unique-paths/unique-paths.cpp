class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m, vector<int>(n,0));
        v[m-1][n-1]=1;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int rowVal=0;
                int colVal=0;
            
                if(j!=n-1) {
                    colVal = v[i][j+1];
                
                }
                if(i!=m-1) rowVal=v[i+1][j];

                v[i][j] += rowVal+colVal;

            }
        }
        return v[0][0];
    }
};