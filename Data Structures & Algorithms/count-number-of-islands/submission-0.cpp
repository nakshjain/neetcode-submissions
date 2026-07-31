class Solution {
private:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& seen, int i, int j){
        if(grid[i][j]=='0') return;
        seen[i][j]=1;
        int drows[] = {-1, 0, 1, 0};
        int dcols[] = {0, -1, 0, 1};
        for(int k=0;k<4;k++){
            int row=i+drows[k];
            int col=j+dcols[k];
            if(row>=0 && col>=0 && row<n && col<m && !seen[row][col]) dfs(grid, seen, row, col);
        }
    }

    int n=0, m=0;
public:
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> seen(n, vector<int>(m, 0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!seen[i][j] && grid[i][j]=='1'){
                    dfs(grid, seen, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
