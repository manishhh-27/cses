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
void f(int n,int s,int e,int m){
    if(n==1){
        cout<<s<<" "<<e<<endl;
        return;
    }
    f(n-1,s,m,e);
    cout<<s<<" "<<e<<endl;
    f(n-1,m,e,s);
}

int main(){
    ll n;
    cin>>n;
    cout<<pow(2,n)-1<<endl;
    f(n,1,3,2);
    
    return 0;
}