class Solution {
  public:
  bool dfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>&visited,vector<bool>&inRecursion){
      visited[u]=true;
      inRecursion[u]=true;
      for(auto &v:adj[u]){
          if(visited[v]==false && dfs(v,adj,visited,inRecursion))
            return true;
          else if(inRecursion[v]==true)
            return true;
      }
      inRecursion[u]=false;
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<bool>visited(V,false);
        vector<bool>inRecursion(V,false);
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(i,adj,visited,inRecursion)){
                return true;
            }
        }
        return false;
    }
};
