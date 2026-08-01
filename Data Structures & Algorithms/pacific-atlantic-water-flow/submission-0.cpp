class Solution {
private:
    int n=0;
    int m=0;

    void dfs(vector<vector<int>>& heights, vector<vector<int>>& ocean, int i, int j){
        ocean[i][j]=1;
        int drows[]={-1, 0, 1, 0};
        int dcols[]={0, -1, 0, 1};
        for(int k=0;k<4;k++){
            int row = i+drows[k];
            int col = j+dcols[k];
            if(row>=0 && row<n && col>=0 && col<m &&
                heights[row][col]>=heights[i][j] && !ocean[row][col]){
                    dfs(heights, ocean, row, col);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0)), atlantic(n, vector<int>(m, 0)), ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    dfs(heights, pacific, i, j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==n-1 || j==m-1){
                    dfs(heights, atlantic, i, j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
