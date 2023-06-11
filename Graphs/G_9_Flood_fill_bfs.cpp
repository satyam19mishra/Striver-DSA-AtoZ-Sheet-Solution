class Solution {
    private:
    void bfs(vector<vector<int>> &image,int row,int col,int init_color,int new_color,
    int del_row[],int del_col[],vector<vector<int>>&ans){
        ans[row][col] = new_color;
        queue<pair<int,int>> q;
        q.push({row,col});
       
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = p.first + del_row[i];
                int ncol = p.second + del_col[i];
                if(nrow>=0 and nrow<image.size() and
                 ncol >=0 and ncol< image[0].size() and 
                 image[nrow][ncol]==init_color and ans[nrow][ncol]!=new_color){
                    ans[nrow][ncol] = new_color;
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int init_color = image[sr][sc];
        int del_row[] = {-1,0,1,0};
        int del_col[] = {0,1,0,-1};
        vector<vector<int>> ans  = image;
        bfs(image,sr,sc,init_color,color,del_row,del_col,ans);
        return ans;
    }
};
