class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        // make a graph
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int>q;
        int cnt=0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                cnt++;
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto &v:adj[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                    cnt++;
                    q.push(v);
                }
            }
        }
        return cnt==numCourses;
    }
};
