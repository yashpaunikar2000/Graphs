class Solution {
public:
int n;
void dfs(vector<vector<int>>& isConnected,int u,vector<bool>&visited){
    for(int v=0;v<n;v++){
        if(!visited[v] && isConnected[u][v]==1){
            visited[v]=true;
            dfs(isConnected,v,visited);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
      n=isConnected.size();
      vector<bool>visited(n,false);
      int cnt=0;
      for(int i=0;i<n;i++){
        if(!visited[i]){
            cnt++;
            dfs(isConnected,i,visited);
        }
      }
      return cnt; 
    }
};
