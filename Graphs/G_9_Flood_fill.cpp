
class Solution {
    
    private:
    void dfs(vector<vector<int>>& image,vector<vector<int>>& visited, int sr, int sc, int newcolor,int inital_color,int drow[],int dcol[],int n, int m){
        visited[sr][sc] = newcolor;
        
        for(int i=0;i<4;i++){
            int nrow = sr + drow[i];
            int ncol = sc + dcol[i];
            
            if(nrow>=0 && nrow< n && ncol >=0 && ncol < m && visited[nrow][ncol]!= newcolor && image[nrow][ncol]==inital_color){
                dfs(image,visited,nrow,ncol,newcolor,inital_color,drow,dcol,n,m);
            }
        }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        int inital_color = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>> visited = image;
        
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        
        dfs(image,visited,sr,sc,newcolor,inital_color,drow,dcol,n,m);
        return visited;
    }
};
