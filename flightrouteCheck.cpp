
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
void dfs(int u, vector<vector<ll>>& adj,vector<ll>& vis,stack<ll>& s){
      vis[u]=1;
      for(int v:adj[u]){
        if(vis[v]==0)
        dfs(v,adj,vis,s);
      }
      s.push(u);

}
void dfs2(int u, vector<vector<ll>>& radj,vector<ll>& vis){
      vis[u]=1;
      for(int v:radj[u]){
        if(vis[v]==0)
        dfs2(v,radj,vis);
      }
   

}

int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
     vector<vector<ll>> radj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);  
        radj[v].push_back(u);        
    }
    stack<ll> s;
    vector<ll> vis(n+1,0);
    dfs(1,adj,vis,s);
    for(int i=1;i<=n;i++){
        if(vis[i]==0)
        {
            cout<<"NO"<<endl;
            cout<<1<<" "<<i<<endl;
            return 0;
        }
    }
    int c=0;
    for(int i=1;i<=n;i++)
    vis[i]=0;

      int prev=-1;
    while(!s.empty()){
       int v=s.top();
       s.pop();
     
       if(vis[v]==0){
             if(c!=0){
                cout<<"NO"<<endl;
                cout<<v<<" "<<prev;
                return 0;
             }
             else{
                prev=v;
             }
             dfs2(v,radj,vis);
             c++;
       } 

    }

    cout<<"YES";





  
   
  
   

   
    return 0;
}