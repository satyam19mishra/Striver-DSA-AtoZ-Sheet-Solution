class Solution{
private:
    void dfs(vector<vector<int>> &visited,vector<vector<char>> &mat,int row, int col, int drow[],int dcol[],int n,int m){
        visited[row][col] = 1;
        
        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow>=0 and nrow < n and ncol >=0 and ncol < m and !visited[nrow][ncol] and mat[nrow][ncol]=='O'){
                dfs(visited,mat,nrow,ncol,drow,dcol,n,m);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
       
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        
        
        //first coloumn
        for(int i=0;i<n;i++){
            if(!visited[i][0] and mat[i][0]=='O'){
                dfs(visited,mat,i,0,drow,dcol,n,m);
            }
        }
        // last colounm
        for(int i=0;i<n;i++){
            if(!visited[i][m-1] and mat[i][m-1]=='O'){
                dfs(visited,mat,i,m-1,drow,dcol,n,m);
            }
        }
        // first row
        for(int j=0;j<m;j++){
            if(!visited[0][j] and mat[0][j]=='O'){
                dfs(visited,mat,0,j,drow,dcol,n,m);
            }
        }
        //last row
        for(int j=0;j<m;j++){
            if(!visited[n-1][j] and mat[n-1][j]=='O'){
                dfs(visited,mat,n-1,j,drow,dcol,n,m);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};
