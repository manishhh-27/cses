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
class DSU{
    public:
    vector<int> par;
    vector<int> size;
     int cmp;
     int ms;
    DSU(int n){
        for(int i=0;i<n;i++){
            par.push_back(i+1);
            size.push_back(1);
            cmp=n;
            ms=1;
           
        }

        /*
           par = vector<int>(n);
        size = vector<int>(n, 1);
        iota(begin(par), end(par), 0);
        cmp=n;
        ms=;
        */
         cout<<"dsu created"<<endl;
    }
    int getParent(int x){
        if(x==par[x])
        return x;

        return par[x]=getParent(par[x]);
    }
    int getsize(int x){
       return size[x] = size[getParent(x)];
    }
    void join(int x,int y){
        cout<<"hello from join";
        x=getParent(x);
        y=getParent(y);
         if (size[x] > size[y])
            swap(x, y);
        if (x == y) return;
        par[x] = y;          
        size[y] += size[x];  
        ms=max(ms,size[y]);
        cmp--;

    }

};
int main(){
    int n,m;
    cin>>n>>m;
    
    DSU d(n);
    cout<<d.par.size();
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
       
        d.join(u-1,v-1);
        cout<<d.cmp<<" "<<d.ms<<endl;
      
    }
    
   
    return 0;
}