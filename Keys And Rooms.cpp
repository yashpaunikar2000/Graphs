class Solution {
public:
void dfs(vector<vector<int>>&rooms,int source,vector<bool>&visited){
    visited[source]=true;
    for(auto &v:rooms[source]){
        if(!visited[v]){
            dfs(rooms,v,visited);
        }
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
        dfs(rooms,0,visited);
        for(bool it:visited){
            if(it==false)
            return false;
        }
        return true;
    }
};
