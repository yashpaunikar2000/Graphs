class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          //building graph
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
         vector<int>result;
        for(auto &dir:prerequisites)
        {
            int a=dir[0];
            int b=dir[1];
            //b----->a
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int>q;
        int cnt=0;
        for(int i=0;i<numCourses;i++)
    {
            if(indegree[i]==0)
        {
            cnt++;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        result.push_back(curr);
        for(int &neighbour:adj[curr])
        {
            indegree[neighbour]--;
            if(indegree[neighbour]==0)
            {
                cnt++;
                q.push(neighbour);
            }
        }
    }
    if(cnt==numCourses)
     return result;
     else
     return {};
    }
};
