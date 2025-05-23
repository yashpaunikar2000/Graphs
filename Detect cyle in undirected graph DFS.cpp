class Solution {
  public:
  bool dfs(int u,int parent,vector<bool>&visited,unordered_map<int , vector<int>>& adj){
      visited[u]=true;
      for(int &v:adj[u]){
          if(v==parent){
              continue;
          }
          if(visited[v]==true){
              return true;//if it is already true means graph has a cycle
          }
          if(dfs(v,u,visited,adj)){
              return true;
          }
      }
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // first of all make it as a adjacency list
        unordered_map<int , vector<int>> adj;
        for(int i=0;i<edges.size();i++)
        {
            int u= edges[i][0];
            int v= edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(visited[i]==false && dfs(i,-1,visited,adj)){
                return true;
            }
        }
        return false;
    }
};
