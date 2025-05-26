class Solution {
  public:
  void bfs(int u,vector<bool>&visited,vector<vector<int>>&adj){
      queue<int>q;
      q.push(u);
      visited[u]=true;
      for(int v=0;v<adj.size();v++){
          if(!visited[v] && adj[u][v]==1){
              bfs(v,visited,adj);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool>visited(V,false);
        int cnt=0;
        for(int i=0;i<V;i++){
                if(!visited[i]){
                bfs(i,visited,adj);
                cnt++;
            }
        }
        return cnt;
    }
};
