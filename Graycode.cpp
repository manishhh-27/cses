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

/*
0
1

00
10
01
11

*/
#define sz(a) (int)a.size()
ll mod=1e9+7;
vector<string> f(int n){
    if(n==1)
    {
        return {"0","1"};
    }
    vector<string> prev=f(n-1);
    vector<string> prev2=prev;

    reverse(prev2.begin(),prev2.end());
    int sz=prev.size();
    int i=0;

    while(i<sz){
      prev[i]=prev[i]+"0";
      string s=prev2[i]+"1";
      prev.push_back(s);
    i++;
    }
    return prev;
}

int main(){
 ll n;
 cin>>n;

vector<string> ans=f(n);
for(auto x: ans){
    cout<<x;
    nl
}
    
    return 0;
}