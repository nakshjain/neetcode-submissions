class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> seen(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i, j}, 0});
                    seen[i][j]=1;
                }
                if(grid[i][j]==-1){
                    seen[i][j]=1;
                }
            }
        }
        int drows[]={-1, 0, 1, 0};
        int dcols[]={0, -1, 0, 1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int val = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int i = row + drows[k];
                int j = col + dcols[k];
                if(i>=0 && i<n && j>=0 && j<m && !seen[i][j]){
                    grid[i][j]=val+1;
                    seen[i][j]=1;
                    q.push({{i, j}, grid[i][j]});
                }
            }           
        }
    }
};
