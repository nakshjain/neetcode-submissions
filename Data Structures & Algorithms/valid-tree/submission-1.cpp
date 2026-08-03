class Solution {
private:
    void dfs(vector<vector<int>>& adj, vector<int>& seen, int index){
        seen[index]=1;
        for(int i=0;i<adj[index].size();i++){
            if(!seen[adj[index][i]]){
                dfs(adj, seen, adj[index][i]);
            }
        }
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> seen(n, 0);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!seen[i]){
                count++;
                dfs(adj, seen, i);
            }
        }
        return edges.size() == n-1 && count==1;
    }
};
