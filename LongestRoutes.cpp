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
int par[100005];
ll mod=1e9+7;
ll dfs(int u, vector<vector<ll>> adj,vector<ll>& vis,vector<ll>& dist){
    vis[u]=1;
    int next=-1;
    ll ans=dist[u];
    for(int v:adj[u]){
       if(vis[v]==0)
       dfs(v,adj,vis,dist);
      
       if(ans<dist[v]){
        next=v;
        ans=dist[v];
       }
     

              }

    
  //  cout<<u<<" "<<ans<<endl;
       if(ans>-1){
    
           dist[u]=1+ans;
           par[next]=u;
       }
    return dist[u];

}
void mark_dfs(ll node, vector<ll> &vis, vector<ll> adj[]){
    vis[node] = 1;
    for(auto child : adj[node]){
        if(!vis[child]){
            mark_dfs(child,vis,adj);
        }
    }
}

//function to return the max_len and store the path using child array
ll dfs(ll node, vector<ll> &dp, vector<ll> adj[],int n, vector<ll> &child){
    //base condition
    if(node==n) return dp[n] = 1;
    //memoization step
    if(dp[node]!=-1) return dp[node];
    ll len = 0;
    //standard dfs approach
    for(auto v : adj[node]){
        ll tmp = dfs(v,dp,adj,n,child);
        //temp_len checks whether the len is coming from the nth node or not
        ll temp_len = tmp==0?0:1+tmp;
        if(temp_len>len){
            // updating the child node and len
            child[node] = v;
            len = temp_len;
        }
    }
    //dp assignment step
    return dp[node] = len;
}
int main(){
     ll n,m;
    cin>>n>>m;
    par[1]=-1;
    vector<ll> adj[n+1];
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    
    }
    vector<ll> vis(n+1,0);
    mark_dfs(1,vis,adj);
    if(!vis[n]) cout<<"IMPOSSIBLE\n";
    else{
        vector<ll> dp(n+1,-1);
        vector<ll> child(n+1,0);
        ll len = dfs(1,dp,adj,n,child);
        int node = 1;
        vector<ll> path;
        //forward traversal to print the path.
        while(node){
            path.pb(node);
            node = child[node];
        }
        cout<<len<<endl;
        for(auto it : path){
            cout<<it<<" ";
        }
    }
    

    
    return 0;
}