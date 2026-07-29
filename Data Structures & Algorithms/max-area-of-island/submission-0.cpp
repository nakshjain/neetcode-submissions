class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int& size){
        int n=grid.size(), m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(!grid[i][j]) return;
        size++;
        grid[i][j]=0;
        dfs(grid, i+1, j, size);
        dfs(grid, i-1, j, size);
        dfs(grid, i, j+1, size);
        dfs(grid, i, j-1, size);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    int size=0;
                    dfs(grid, i, j, size);
                    maxSize=max(maxSize, size);
                }
            }
        }
        return maxSize;
    }
};
