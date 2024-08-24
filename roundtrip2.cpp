#include <bits/stdc++.h>
using namespace std; 
#define ll long long int

#define fi(i,a,b)  for(ll i=a;i<=b;i++)
#define fd(i,a,b)  for(int i=a;i>=b;i--)
#define nl  cout<<"\n";
#define yes  cout<<"YES\n";
#define no  cout<<"NO\n";
#define pb push_back
#define vll vector< long long int >
#define read(v) for(auto &itt:v) cin>>itt;
#define print(v) for(auto &itt:v) cout<<itt<<' ' ; cout<<endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(),v.rend()

#define sz(a) (int)a.size()
ll mod=1e9+7;
vector<int> v;
/* cycle detection in a directed graph*/
bool dfs(int u,vector<int> & rs,vector<vector<int>>& adj,vector<int>& vis,vector<int>& ans){
    vis[u]=1;
    rs[u]=1;
    ans.push_back(u);
  // cout<<u<<" "<<endl;
    for(auto x:adj[u]){
       
        if(vis[x]==false )
        {
               if(dfs(x,rs,adj,vis,ans))
               return true;
        }
    
        else if(rs[x])
       { 
         // cout<<x<<" "<<p<<endl;
        v=ans;
        v.push_back(x);
        return true;}
    }
    rs[u]=0;
    ans.pop_back();
    return false;
    
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
      
    }
    
    vector<int> vis(n+1,0),rs(n+1,0),ans;
    fi(i,1,n){
        if(vis[i])
        continue;
    if(dfs(i,rs,adj,vis,ans)){
    
           int c=0;
           while(c<v.size() and v.back()!=v[c] )
           c++;
            cout<<v.size()-c<<endl;
            for(int i=c;i<v.size();i++)
            cout<<v[i]<<" ";
            cout<<endl;
            return 0;
    }
    v.clear();
    ans.clear();
    

        

    }

     cout<<"IMPOSSIBLE"<<endl;
   
    return 0;
}