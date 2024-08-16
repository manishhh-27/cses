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


/*
Firstly find shortest path from 1 to every node. (answers in array A)

-Then find shortest path from N to every node (on Inverted graph) which means finding shortest path from every node to N.(answers in array B)

-Then consider each edge(u,v) in graph , suppose you are applying discount on that edge... then if we can reach 1 to u and N to v (in short v to N) then ans=min( ans , A[u] + weight/2 + B[v] ).
*/
vector<ll> dj(ll n,vector<vector<pair<ll,ll>>> adj,int s){
    vector<ll> vis(n+1,0);
    vector<ll> dist(n+1,LLONG_MAX);
    dist[s]=0;
    
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,s});
   
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
    return dist;

}

#define sz(a) (int)a.size()
ll mod=1e9+7;
int main(){
    ll n,m;
    cin>>n>>m;
     vector<vector<pair<ll,ll>>> adj(n+1);
      vector<vector<pair<ll,ll>>> radj(n+1);
     
    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        radj[v].push_back({u,c});
    }
    vector<ll> a,b;
    ll ans=LLONG_MAX;
    a=dj(n,adj,1);
    b=dj(n,radj,n);
    for(int i=1;i<=n;i++){
        for(auto x:adj[i]){
            ll j=x.first,w=x.second;
            if(a[i]!=LLONG_MAX and b[j]!=LLONG_MAX){
                ans=min(ans,a[i]+b[j]+w/2);
            }
        }
    }
    cout<<ans;
    nl
   
    return 0;
}