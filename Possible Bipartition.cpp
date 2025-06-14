class Solution {
public:
bool bfsBipartite(unordered_map<int,vector<int>>&adj,vector<int>&color,int node){
    queue<int>q;
    q.push(node);
    color[node]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto &v:adj[u]){
            // check the parent child color are same or not
            if(color[v]==color[u]){
                return false;
            }
            if(color[v]==-1){
            // means it is not processed yet
                color[v]=1-color[u];
                q.push(v);
            }
        }
    }
    return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>color(n+1,-1);
        // Make Adjacency List
        unordered_map<int,vector<int>>adj;
        for(auto &vec:dislikes){
            int u=vec[0];
            int v=vec[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        // traverse through every Node
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(bfsBipartite(adj,color,i)==false){
                return false;
            }
            }
        }
        return true;
    }
};
