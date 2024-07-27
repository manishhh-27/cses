#include <bits/stdc++.h>
using namespace std; 
void f(int u,int t,vector<vector<int>>& adj,vector<int>& team){
                
           team[u]=t;
          for(auto x:adj[u]){
         if(team[x]==0){
            int c=(t==1)?2:1;
            f(x,c,adj,team);
         }
         else if(team[x]==t){
            team[x]=-1;
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
    vector<int> team(n+1,0);
    for(int i=1;i<=n;i++){
        if(team[i]==0){
            f(i,1,adj,team);
        }
        if(team[i]==-1)
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<team[i]<<" ";
    }
    cout<<endl;
    return 0;
}