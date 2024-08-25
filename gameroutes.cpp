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
int f( vector<vector<ll>>& adj,int i,vector<ll>& dp){
if(dp[i]!=-1)
return dp[i];
ll ans=0;
/*

reverse the graph

for a->c & b->c & ......

ans[c]=ans[a]+ans[c]+ ....

ans[1]=1


*/
for(auto x:adj[i]){
    ans=(ans%mod+f(adj,x,dp)%mod)%mod;
}

return dp[i]=ans%mod;

}
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[v].push_back(u);     
    }
   vector<ll> dp(n+1,-1);
   dp[1]=1;
   cout<<f(adj,n,dp);
   
  
   

   
    return 0;
}