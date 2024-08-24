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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        
    }

        
        vector<int> indegree(n+1,0);
        for(int i=1;i<=n;i++)
        {
            for(int u:adj[i])
                indegree[u]++;
        }
        int c=0;
        queue<int> q;
         for(int i=1;i<=n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> ans;
        
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            c++;
            for(int v:adj[u])
                if(--indegree[v]==0)
                    q.push(v);


        }
        if(c!=n)
        {
            cout<<"IMPOSSIBLE";
            nl
            return 0;
        }
        for(auto x:ans)
        cout<<x<<" ";
        nl


        return 0;

}