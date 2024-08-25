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
vector<ll> v;
bool dfs(int u,int p,vector<vector<ll>>& adj,vector<ll>& vis,vector<ll>& ans){
    vis[u]=1;
    
    ans.push_back(u);
   //cout<<u<<" "<<p<<endl;
    for(auto x:adj[u]){
       
        if(vis[x]==false )
        {
               if(dfs(x,u,adj,vis,ans))
               return true;
        }
    
        else if(x!=p)
       { 
         // cout<<x<<" "<<p<<endl;
        v=ans;
        v.push_back(x);
        return true;}
    }
    ans.pop_back();
    return false;
    
}
int main(){
  
 ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1); 
    vector<vector<ll>>  edge;
    for(ll i=0;i<m;i++){
        ll u,v,c;
        cin>>u>>v>>c;
       
          edge.push_back({u,v,c});
    
    }
    /*
    for(int i=1;i<=n;i++){
      edge.push_back({0,i,0});
    }
    what if graph has multiple components
    */
 
    vector<ll> d(n+1,1e18);
    
    d[1]=0;
    bool flag=0;
    ll x;
    vector<ll> par(n+1,-1);
    for (int i=1; i<=n;i++) {
        flag=0;
        for (auto e:edge){
              ll u=e[0],v=e[1],w=e[2];
              if( d[u]+w<d[v]){
                  flag=1;
                  par[v]=u;
                  x=v;
                  d[v]=d[u]+w;
                 
              }
        }
      }

      if(flag==false){
        cout<<"NO"<<endl;;
        return 0;
      }
      for(ll i=0;i<n;i++)
{
  x=par[x];
}    


      if(flag){
      cout<<"YES"<<endl;
       vector<ll> ans;
for(int i=x;;x=par[x]){
  ans.push_back(x);
  if(x==i and ans.size()>1)
  break;
}
reverse(ans.begin(),ans.end());
for(auto a:ans)
cout<<a<<" ";
nl
   
    }
    else
   cout<<"NO"<<endl;
        

    

      

      
      
return 0;
}