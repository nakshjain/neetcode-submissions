class Solution {
private:
    bool dfs(const vector<vector<int>>& adj, vector<int>& visited, vector<int>& recursive, int index){
        visited[index]=1;
        recursive[index]=1;
        for(const int i: adj[index]){
            if((visited[i] && recursive[i]) || dfs(adj, visited, recursive, i)) return true;
        }
        recursive[index]=0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<int> recursive(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto v: prerequisites){
            adj[v[0]].push_back(v[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && dfs(adj, visited, recursive, i)) return false;
        }
        return true;
    }
};
