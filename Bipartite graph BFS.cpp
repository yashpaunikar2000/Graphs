class Solution {
  public:
  bool bfs(vector<vector<int>>&adj,int node,vector<int>&color,int currcolor){
      queue<int>q;
      color[node]=currcolor;
      q.push(node);
      while(!q.empty()){
          int u=q.front();
          q.pop();
          for(auto &v:adj[u]){
              if(color[v]==color[u])
              return false;
              if(color[v]==-1){
                  color[v]=1-color[u];
                  q.push(v);
              }
          }
      }
      return true;
  }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // first, make a graph
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(bfs(adj,i,color,1)==false)
                return false;
            }
        }
        return true;
        
    }
};
