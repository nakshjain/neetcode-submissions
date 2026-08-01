class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i, j}, 0});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int ans=0;
        int drows[]={-1, 0, 1, 0};
        int dcols[]={0, -1, 0, 1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int curTime = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int i = row + drows[k];
                int j = col + dcols[k];
                if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1){
                    q.push({{i, j}, curTime+1});
                    grid[i][j]=2;
                    fresh--;
                }
            }
            ans=curTime;
        }
        return fresh==0 ? ans : -1;
    }
};
