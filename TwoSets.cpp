
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
ll mod=998244353;
 
 
class DSU {
private:
    vector<int> parent, size;
public:
    DSU(int n) {            // very beginning of your initialisation.
        parent = vector<int>(n);
        size = vector<int>(n, 1);
        iota(begin(parent), end(parent), 0);
    }
    
    int getParent(int x) {      // get the leader
        if (parent[x] == x) return x;
        return parent[x] = getParent(parent[x]);
    }
 
    void join(int x, int y) {
        x = getParent(x);       //A
        y = getParent(y);       //A
        if (size[x] > size[y])
            swap(x, y);
        if (x == y) return;
        parent[x] = y;          
        size[y] += size[x];         // sz increment.
    }
 
    int getSize(int x) {
        return size[x] = size[getParent(x)];
    }
};
 
vector<ll> factors(ll  n) { //returns vector of prime factors of n
vector<ll> f;
for (ll x = 2; x*x <= n; x++) {
while (n%x == 0) {
f.push_back(x);
n /= x;
}
}
if (n > 1) f.push_back(n);
return f;
}
 
int modpow(int x, int n, int m) {  //for calulating x^y%m
if (n == 0) return 1%m;
long long u = modpow(x,n/2,m);
u = (u*u)%m;
if (n%2 == 1) u = (u*x)%m;
return u;
}
 
bool kthsetbit(int n, int k)  
{
    if ((n >> (k )) & 1)
        return true;         
    else
        return false;
}
 
ll mul(ll a,ll b){     //a*b%mod
    return ((a%mod)*(b%mod))%mod;
}
 
 
ll binpow(ll a,ll b){
    if(b==0)           //(a^b)%mod
    return 1;
    ll t=binpow(a,b/2);
    t=mul(t,t);
    if(b%2)
    return mul(t,a);
     return t;
} 
 
ll minv(ll a,ll m=mod){    // for modulo inverse
    return binpow(a,m-2);
}
 
const ll sz=2e5+1;
ll fact[sz],invfact[sz];
 
void precalc(){
    fact[0]=1;             
    invfact[0]=1;
    fi(i,1,sz-1){
        fact[i]=mul(fact[i-1],i);
        invfact[i]=mul(invfact[i-1],minv(i));
    }
}
 
ll nCr(ll n,ll r){
    
    return mul(fact[n],mul(invfact[r],invfact[n-r]));
}
 
int mex(vll& a,ll n){
 ll b[n];
fi(i,0,n-1){b[i]=a[i];}
sort(b,b+n);
ll k=0;
fi(i,0,n-1){
    if(b[i]==k){ k++;}
    if(b[i]>k)break;
}
return k;
}
bool isprime(ll n)
{   
    for(ll i=2;i*i<=n;i++){
        if(n%i==0)
        return false;
    }
    return true;
}
 
ll msb(ll n){ 
                   ll pos=0;
                    while(n)
                    {n=n>>1; pos++; } 
                    return pos-1; }
 
 
bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}
 
void maxheapify(vll& a,ll i){
    int n=a.size();
    ll l=2*i+1;
    ll r=2*i+2 ;
    ll largest=i;
    if(l<n&&a[l]>a[largest])
    largest=l;
    if(r<n&&a[r]>a[largest])
    largest=r;
    if(largest!=i){
        swap(a[i],a[largest]);
        maxheapify(a,largest);
 
    }
 
}
 
int parent(int i)
{
    return (i-1)/2;
}
void insert(vll& a,int x){
    int s=a.size();
    a.push_back(x);
   int i=s;
   
   while(i!=0&&a[parent(i)]<a[i]){
       swap(a[i],a[parent(i)]);
       i=parent(i);
   }
 
}
int getmax(vll& a){
    int ans=a[0];
    int s=a.size();
    a[0]=a[s-1];
    maxheapify(a,0);
    return ans;
}
 
 
void buildheap(vll& a){
    int n=a.size();
    for(ll i=(n -2)/2;i>=0;i--)
    maxheapify(a,i);
}
 
void solve()
{
ll n;
cin>>n;
vll v1,v2;
ll a=0,b=0;
ll s=n*(n+1);
s=s/2;
if(s&1){
    no
    return;
}
 
a=s/2;
fd(i,n,1){
    if(i<=a)
    {a-=i;
    v1.push_back(i);}
    else
   { 
      v2.push_back(i);}
 
}
if(a==b)
yes
else
no
if(a==b){
    cout<<v1.size();
    nl
    for(auto x:v1)
    cout<<x<<" ";
    nl
      cout<<v2.size();
    nl
    for(auto x:v2)
    cout<<x<<" ";
    nl
}
}
 
 
 
 
 
 
 
int main(){
	// your code goes here
    
 
    
    	ll tt=1;
 
  //cin>>tt;
      //precalc();
 ll x=1;
 
	while(tt--){
       // cout<<x<<" ";
        x++;
    solve();
	}
	return 0;
	
}