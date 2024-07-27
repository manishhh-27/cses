#include <bits/stdc++.h>
using namespace std;  
vector<int> ans;

void dfs(int u,vector<vector<int>>& adj,vector<bool>& vis,vector<int>& v){
    vis[u]=true;
    int n=adj.size()-1;
    v.push_back(u);

    if(u==n){
        if(ans.size()==0 or ans.size()>v.size())
        ans=v;
    
    }
    for(auto x:adj[u]){
        if(vis[x]==false){
            dfs(x,adj,vis,v);
        }
    }
    v.pop_back();
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
    int res=0;
   vector<bool> vis(n+1,false);
   vector<int> v(n+1,-1);
   queue<int> q;
   q.push(1);
   vis[1]=1;
   while(!q.empty()){
    int u=q.front();
    q.pop();
    if(u==n){
        vector<int> ans;
        ans.push_back(n);
        while(u!=1){
           u=v[u];
        ans.push_back(u);
        }
        
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<" ";
        cout<<endl;
        return 0;
    }
    for(auto x:adj[u]){
      if(vis[x]==false){
        vis[x]=true;
        q.push(x);
        v[x]=u;

      }
    }
    res++;
   }
   cout<<"IMPOSSIBLE"<<endl;
    return 0;
}