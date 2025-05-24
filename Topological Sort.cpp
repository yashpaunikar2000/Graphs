class Solution {
  public:
  void dfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>&visited,stack<int>&st){
      visited[u]=true;
      for(auto &v:adj[u]){
          if(!visited[v]){
              dfs(v,adj,visited,st);
          }
      }
      st.push(u);
  }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<bool>visited(V,false);
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
