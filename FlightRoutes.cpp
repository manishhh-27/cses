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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});;   
    }
    vector<ll> vis(n+1,0);
    vector<vector<ll>> dist(n+1,vector<ll> (k,LLONG_MAX));
    dist[1][0]=0;
    
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
   
    while(!pq.empty()){
        
         ll u = pq.top().second;
		ll d = pq.top().first;
		pq.pop();
 
		if(dist[u][k-1] < d) continue;
         for(auto x:adj[u]){
 
            ll v=x.first;
            ll nd=d+x.second;
            if(nd<dist[v][k-1]){
                dist[v][k-1]=nd;
                pq.push({nd,v});
                sort(dist[v].begin(),dist[v].end());
            }
 
 
         }
    }
    for(ll i=0;i<k;i++){
        cout<<dist[n][i]<<" ";
    }
 
          
          
    
    
    return 0;
}