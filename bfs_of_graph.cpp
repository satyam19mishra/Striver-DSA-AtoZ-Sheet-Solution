#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    //bfs of the graph

    int vis[n+1] = {0};
    vis[1] = 1;
    queue<int> q;
    q.push(1);

    vector<int> bfs;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }

    for(int i=0;i<bfs.size();i++){
        cout << bfs[i] << endl;
    }
    return 0;

}