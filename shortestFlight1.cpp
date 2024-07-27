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
int main(){

 ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(ll i=0;i<m;i++){
        ll u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
    
    }
    vector<ll> vis(n+1,0);
    vector<ll> dist(n+1,LLONG_MAX);
    dist[1]=0;
    
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
   
    while(!pq.empty()){
        
         ll u=pq.top().second;
         pq.pop();
         if(vis[u])
         continue;
         vis[u]=1;
         for(auto x:adj[u]){

            ll v=x.first;
            ll nd=dist[u]+x.second;
            if(nd<dist[v]){
                dist[v]=nd;
                pq.push({nd,v});
            }


         }
    }
    for(ll i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }



return 0;
}