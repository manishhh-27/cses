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
void dfs(int u, vector<vector<pair<ll,ll>>>& adj,vector<ll>& vis){
    vis[u]=1;

    for(auto x:adj[u]){
        if(vis[x.first]==0)
        {
            dfs(x.first,adj,vis);
        }
    }
}

int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
         adj[v].push_back({u,c});

    }

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;

    vector<ll> vis(n+1,0);
    dfs(1,adj,vis);
    bool flag=false;
    for(int i=1;i<=n;i++){
        if(vis[i]){
            vis[i]=0;
        }
        else{
            flag=true;
        }
    }
    if(flag){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    pq.push({0,1});

    ll ans=0;
     ll c=0;
    while(!pq.empty()){
        
        int w=pq.top().first;
        int u=pq.top().second;
        pq.pop();

        if(vis[u]==1)
        continue;
        ans+=w;
     
        //cout<<u<<" "<<w<<endl;
        vis[u]=1;
        for(auto x:adj[u]){
            int v=x.first;
            int d=x.second;
            if(vis[v]==0){
                pq.push({d,v});
            }
        }


    }
   


    cout<<ans;
   
  
   

   
    return 0;
}