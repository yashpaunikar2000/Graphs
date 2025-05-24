class Solution {
  public:
  bool bfs(int u,int parent,unordered_map<int,vector<int>>&adj,vector<bool>&visited){
      queue<pair<int,int>>q;
      q.push({u,-1});
      visited[u]=true;
      while(!q.empty()){
          auto it=q.front();
          q.pop();
          int u=it.first;
          int parent=it.second;
          for(auto &v:adj[u]){
              if(visited[v]==false){
                  visited[v]=true;
                  q.push({v,u});
              }else if(v!=parent){
                //  parent naa hokar visited hai.....means cycle hai
                  return true;
              }
          }
      }
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<bool>visited(V,false);
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<V;i++){
            if(!visited[i] && bfs(i,-1,adj,visited)){
                return true;
            }
        }
        return false;
    }
};
