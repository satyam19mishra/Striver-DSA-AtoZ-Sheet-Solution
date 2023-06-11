
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    int n = grid.size();
	    int m = grid[0].size();
	    
	   // int visited[n+1][m+1] = {0};
	    vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(),0));
	    vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
	    
	    queue<pair<pair<int,int>,int>> q;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                visited[i][j] = 1;
	                
	            }
	        }
	    }
	    
	    int drow[4] = {-1,0,1,0};
	    int dcol[4] = {0,1,0,-1};
	    
	    while(!q.empty()){
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int step = q.front().second;
	       
	        dist[row][col] = step;
	        
	        q.pop();
	        
	        for(int i=0;i<4;i++){
	            int nrow = row + drow[i];
	            int ncol = col + dcol[i];
	            
	            if(nrow>=0 && nrow < n && ncol>=0 && ncol < m && visited[nrow][ncol]==0){
	                visited[nrow][ncol] = 1;
	                q.push({{nrow,ncol},step + 1});
	            }
	        }
	    }
	    return dist;
	}
};
