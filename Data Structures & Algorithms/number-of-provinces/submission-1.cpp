class Solution {
private:
    void dfs(vector<vector<int>>& adjLs, vector<int>& visited, int node){
        visited[node]=1;
        for(auto it: adjLs[node]){
            if(!visited[it]){
                dfs(adjLs, visited, it);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<vector<int>> adjLs(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j] && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<int> visited(v, 0);
        int count=0;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                count++;
                dfs(adjLs, visited, i);
            }
        }
        return count;
    }
};