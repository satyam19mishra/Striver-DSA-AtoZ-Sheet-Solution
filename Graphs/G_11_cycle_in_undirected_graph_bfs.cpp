
class Solution {
    private:
    bool bfs(vector<int> adj[],int visited[],int curr){
        
        queue<pair<int,int>> q;
        q.push({curr,-1});
        visited[curr] = 1;
        
        while(!q.empty()){
            pair<int,int> data = q.front();
            int node = data.first;
            int parent = data.second;
            q.pop();
            for(auto it : adj[node]){
                if(it !=parent && visited[it]!=1){
                    visited[it] = 1;
                    q.push({it,node});
                }else if(it !=parent ) return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        int visited[V] = {0};
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfs(adj,visited,i)) return true ;
            }
        }
        return false;
    }
};
