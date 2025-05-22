class Solution {
  public:
  void dfs(int u,vector<int>&ans,vector<vector<int>>& adj,vector<bool>&visited){
    //   first of all make thew node visited
      visited[u]=true;
      ans.push_back(u);
      for(auto &v:adj[u]){
          if(!visited[v]){
              visited[v]=true;
              dfs(v,ans,adj,visited);
          }
      }
}
    vector<int> dfs(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int>ans;
        vector<bool>visited(V,false);
        dfs(0,ans,adj,visited);
        return ans;
    }
};
