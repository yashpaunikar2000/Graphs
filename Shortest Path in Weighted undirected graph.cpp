class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        // constructing the adjacency list
        unordered_map<int, vector<pair<int, int>>> adj;
    
        for(auto vec: edges){
            auto u = vec[0];
            auto v = vec[1];
            auto wt = vec[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        vector<int>result(n+1,INT_MAX);
        vector<int>parent(n+1);
        // 
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        result[1]=0;
        q.push({0,1});
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int dist=it.first;
            int node=it.second;
            for(auto &v:adj[node]){
                int curr=v.first;
                int wt=v.second;
                if(dist+wt<result[curr]){
                    result[curr]=dist+wt;
                    q.push({dist+wt,curr});
                    parent[curr]=node;//parent of curr is 'node'.
                }
            }
        }
        // one edge case
        int destnode=n;
        if(result[destnode]==INT_MAX)
        return { -1 };
        // now store path
        vector<int>path;
        while(parent[destnode]!=destnode){
            path.push_back(destnode);
            destnode=parent[destnode];
        }
        path.push_back(1);
        path.push_back(result[n]);
        reverse(begin(path),end(path));
        return path;
    }
};
