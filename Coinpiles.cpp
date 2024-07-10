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
/*
x+2y=a
2x+y=b;

2(a-2y)+y=b;
2a-b=3y;

x+2(b-2x)=a
2b-a=3x




*/
bool f(int a,int b){
  if(a==0 and b==0)
  return true;
  if(a<=0 or b<=0)
  return false;


  return f(a-1,b-2) or f(a-2,b-1);
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        int v1=2*a -b;
        int v2=2*b-a;
        if(a==0 and b==0)
        yes
        else if((v1>=0  and v1%3==0)  and ( v2>=0 and v2%3==0) )
        yes
        else 
        no
    }

    
    return 0;
}