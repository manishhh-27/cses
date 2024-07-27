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
int main(){
 int n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll >> dist(n+1,vector<ll> (n+1,LLONG_MAX));
      for(int i=0;i<=n;i++)
            dist[i][i]=0;
    for(int i=0;i<m;i++){
        ll u,v,c;
        cin>>u>>v>>c;
        dist[u][v]=min(c,dist[u][v]);
        dist[v][u]=min(dist[v][u],c);
    
    }

          for (int k = 1; k <=n; k++) {
    
        for (int i = 1; i <=n; i++) {
            
            for (int j = 1; j <=n ; j++) {
               
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != LLONG_MAX && dist[i][k] != LLONG_MAX))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    vector<vector<ll>> v;
    fi(i,1,q){
        ll x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    for(auto x:v){
        if(dist[x[0]][x[1]]==LLONG_MAX)
       cout<< -1;
       else 
       cout<<dist[x[0]][x[1]];
       cout<<endl;
    }

return 0;
}