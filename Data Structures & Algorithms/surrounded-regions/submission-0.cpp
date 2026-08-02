class Solution {
private:
    int n = 0;
    int m = 0;
    void dfs(vector<vector<char>>& board, vector<vector<int>>& seen, int i, int j){
        seen[i][j]=1;
        int drows[] = {-1, 0, 1, 0};
        int dcols[] = {0, -1, 0, 1};
        for(int k=0;k<4;k++){
            int row = i + drows[k];
            int col = j + dcols[k];
            if(row>=0 && row<n &&
                col>=0 && col<m &&
                !seen[row][col] && board[row][col]=='O'){
                    dfs(board, seen, row, col);
                }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>> seen(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(!seen[i][j] && board[i][j]=='O'){
                        dfs(board, seen, i, j);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!seen[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
