class Solution {
public:
int n,m;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // Directional Arrays
        int dr[]={-1,-1,-1,0,0,1,1,1};
        int dc[]={-1,0,1,-1,1,-1,0,1};
        n=grid.size();
        m=grid[0].size();
        // edges case
        if(grid[0][0]==1){
            return -1;
        }
        // Need a queue data structure to store 0 cells
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        // take variable to check level
        int level=0;
        // just pop the element from the queue until it gets empty
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto it=q.front();
                int r=it.first;
                int c=it.second;
                q.pop();
                // check if we reached at (n-1,m-1)point just return your level
                if(r==n-1 && c==m-1){
                    return level+1;
                }
                // now check at the all 8 directions
                for(int i=0;i<8;i++){
                    int row=r+dr[i];
                    int col=c+dc[i];
                    // check it is out of the range or not
                    if(row>=0 && row<n && col>=0 && col<m&& grid[row][col]==0){
                        //push into the queue and make visited in place
                        q.push({row,col});
                        grid[row][col]=1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
