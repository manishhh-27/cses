#include <bits/stdc++.h>
using namespace std; 
#define ll long long int
#define fi(i,a,b)  for(ll i=a;i<=b;i++)
#define fd(i,a,b)  for(ll i=a;i>=b;i--)
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
void dfs(vector<vector<ll>>&g, vector<ll>&s, int u) {
  s[u] = 1;
  for(auto v:g[u])
    if (!s[v])
      dfs(g, s, v);
}
/*
bellman ford : finds the minimum distance 
for maximum dist negate the values

do dfs from source and destination to check whether any negative cycle is connected to source and destination or not



*/
int main(){
  
 ll n,m;
    cin>>n>>m;
    vector<vector<ll>> a(n+1);
    vector<vector<ll>> b(n+1);
    vector<vector<ll>>  edge;
    vector<ll> vis1(n+1,0);
    vector<ll> vis2(n+1,0);
    for(ll i=0;i<m;i++){
        ll u,v,c;
        cin>>u>>v>>c;
        a[u].push_back(v);
          b[v].push_back(u);
          edge.push_back({u,v,-1*c});
    
    }
    dfs(a,vis1,1);
    dfs(b,vis2,n);
    vector<ll> d(n+1,1e18);
    
    d[1]=0;
    bool flag=0;
    
for (int i=1; i<=n;i++) {
        flag=0;
        for (auto e:edge){
              ll u=e[0],v=e[1],w=e[2];
              if(vis1[u] and vis2[v] and d[u]+w<d[v]){
                  flag=1;
                  d[v]=d[u]+w;
              }
        }
      }
      if(flag)cout<<-1;
      else cout<<d[n]*-1;
return 0;
}