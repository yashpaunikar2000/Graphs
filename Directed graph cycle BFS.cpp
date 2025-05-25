class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
         //   detecting cycle using KAHN'S algorithm (BFS)
    queue<int>q;
     vector<int>indegree(V,0);
    // first of all, make adjacency list
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    // assigning the indegree to all nodes
    for(int u=0;u<V;u++){
        for(auto &v:adj[u]){
            indegree[v]++;
        }
    }
    // the nodes whose indegree zero(0),push into the stack
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int nodecount=0;
    //now do the simple BFS
    while(!q.empty()){
        int u=q.front();
        nodecount++;
        q.pop();
        for(auto &v:adj[u]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
        return nodecount!=V;
        
    }
};
