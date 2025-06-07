class Solution {
  public:
    // PRIM'S ALGORITHM'S
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<bool>visited(V,false);
        // take sum variable to store minimum edge weight
        int sum=0;
        // {wt,node}
        q.push({0,0});
        while(!q.empty()){
            auto it=q.top();
            int wt=it.first;
            int node=it.second;
            q.pop();
            // check it is visited or not
            if(visited[node]==true)continue;
            if(visited[node]==false){
                visited[node]=true;
            }
            sum=sum+wt;
            // now check on which node , the current node is edging
            for(auto &v:adj[node]){
                int neigh=   v[0];
                int neigh_wt=v[1];
                if(visited[neigh]==false){
                    q.push({neigh_wt,neigh});
                }
            }
        }
        return sum;
    }
};
