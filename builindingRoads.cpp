#include <bits/stdc++.h>
 
using namespace std;  
void dfs(int u,vector<vector<int>>& adj,vector<bool>& vis){
    vis[u]=true;
    for(auto x:adj[u]){
        if(vis[x]==false){
            dfs(x,adj,vis);
        }
    }
}
int main(){

    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n+1,false);
    vector<vector<int>> ans;
    int res=0;
    for(int i=1;i<=n;i++){
           if(vis[i]==false){
            dfs(i,adj,vis);
            if(res>0)
            ans[res-1].push_back(i);
            ans.push_back({i});
               res++;
           }
    }
    cout<<res-1<<endl;
   for(int i=0;i<res-1;i++){
    cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
   }
    return 0;
}