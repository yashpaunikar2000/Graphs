class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int u,vector<int>&ans,vector<vector<int>> &adj,vector<bool>&visited){
        queue<int>q;
        q.push(u);
        visited[u]=true;
        ans.push_back(u);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &v:adj[u]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                    ans.push_back(v);
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        int V=adj.size();
        vector<int>ans;
        vector<bool>visited(V,false);
        bfs(0,ans,adj,visited);
        return ans;
    }
};
