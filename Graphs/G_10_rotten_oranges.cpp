class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        // it will take space of nxm 
        queue<pair<pair<int,int>,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        // vsited array will take an space of nxm
        int visited[n][m];
        // this will run for nxm times 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }else{
                    visited[i][j] = 0;
                }
            }
        }
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        int max_tm = 0;
        // this loop will run for nxmx4 times
        while(!q.empty()){
            pair<pair<int,int>,int> node = q.front();
         
            int row = node.first.first;
            int col = node.first.second;
            int tim = node.second;
            max_tm = max(max_tm,tim);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && visited[nrow][ncol] == 0 && grid[nrow][ncol] ==1){
                    q.push({{nrow,ncol},tim + 1});
                    visited[nrow][ncol] = 2;
                }
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and visited[i][j]!=2) return -1;
            }
        }
        return max_tm;
        
        
        // TC - O(nxm)
        // sc = O(nxm)
    }
};
