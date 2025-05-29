// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // take a min heap to get min distance at top
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<int>result(V,INT_MAX);
        // make a graph first
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        result[src]=0;
        q.push({0,src});//{distance,source_node}
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int dist=it.first;
            int node=it.second;
            for(auto &neighbour:adj[node]){
            
            int nieghb_node=neighbour.first;
            
            int dist_neighb=neighbour.second;
            
            if(dist+dist_neighb<result[nieghb_node]){
                result[nieghb_node]=dist+dist_neighb;
                q.push({dist+dist_neighb,nieghb_node});
            }
            }
        }
         return result;  
    }
};
