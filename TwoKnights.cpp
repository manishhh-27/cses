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
// brute force - tle
int solve(int t){
    int ans=0;
    for(int i=1;i<=t;i++){
        for(int j=1;j<=t;j++){
            int r,c;
            int mark=0;
            r=i+2,c=j+1;
            if(r>=1&&r<=t&&c>=1&&c<=t)
             mark++;
             r=i+2,c=j-1;
            if(r>=1&&r<=t&&c>=1&&c<=t)
             mark++;
             r=i-2,c=j+1;
            if(r>=1&&r<=t&&c>=1&&c<=t)
             mark++;
             r=i-2,c=j-1;
            if(r>=1&&r<=t&&c>=1&&c<=t)
             mark++;
              r=j+2,c=i+1;
            if(r>=1&&r<=t&&c>=1&&c<=t)
             mark++;
             r=j+2,c=i-1;
            if(r>=1&&r<=t&&c>=1&&c<=t)
             mark++;
             r=j-2,c=i+1;
            if(r>=1&&r<=t&&c>=1&&c<=t)
             mark++;
             r=j-2,c=i-1;
            if(r>=1&&r<=t&&c>=1&&c<=t)
             mark++;

             ans+=(t*t)-mark-1;
        }
    }
    return ans/2;
}
int main(){
    
  ll t;
  cin>>t;
  cout<<0<<endl;
 for(long long i=2;i<=t;i++){
     cout<<(((i*i)*(i*i-1))/2)-(4*(i-1)*(i-2))<<endl;



 }


    
    return 0;
}