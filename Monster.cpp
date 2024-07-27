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
bool flag=false;
vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
vector<char> dr={'D','R','U','L'};
void dfs(int x,int y,int s,char c, vector<vector<char>>& adj, vector<vector<int>>& vis, vector<vector<int>>& vism,vector<char>& ans){
int n=adj.size(),m=adj[0].size();
vis[x][y]=1;
ans.push_back(c);
if((x==0 or y==0 or x==n-1 or y==m-1 ) and flag==false)
                {

                   // cout<<x<< " "<<y<<endl;
                    cout<<"YES"<<endl;
                    cout<<ans.size()-1<<endl;
                     for(int i=1;i<ans.size();i++)
                     {
                        cout<<ans[i];
                     }
                     flag=true;
                    return;
                }
            
             for(int i=0;i<4;i++){
              int nx=x+dir[i][0],ny=y+dir[i][1];
                        
                     
              if(nx>=0 and ny>=0 and nx<n and ny<m and vis[nx][ny]==-1 and adj[nx][ny]!='#' and (vism[nx][ny]>(s+1) or vism[nx][ny]==-1)){
                           //   cout<<nx<<ny<<" "<<adj[nx][ny]<<" "<<vism[nx][ny]<<" "<<s<<endl;
                             dfs(nx,ny,s+1,dr[i],adj,vis,vism,ans);
                            
                    }
                }

ans.pop_back();




}

int main(){
    int n,m;
    cin>>n>>m;

     queue<pair<int,int>> qm;
     queue<pair<int,int>> q;
     vector<vector<char>> adj(n,vector<char>(m));
     vector<vector<int>> vis(n,vector<int>(m,-1));
     vector<vector<int>> vism(n,vector<int>(m,-1));
    // vector<vector<char>> ans(n,vector<char>(m));
     fi(i,0,n-1){
        string s;
        cin>>s;
        fi(j,0,m-1)
        {
            adj[i][j]=s[j];
            
            if(adj[i][j]=='M'){
                 qm.push({i,j});
                 vism[i][j]=0;
            }
            else if(adj[i][j]=='A'){
                 q.push({i,j});
                 vis[i][j]=0;
            }

        }
     }
    
    int min=1;
    while(!qm.empty()){
        
              int sm=qm.size();
            
              for(int i=0;i<sm;i++){
                int x=qm.front().first,y=qm.front().second;
                qm.pop();
                 for(auto d:dir){
                    int nx=x+d[0],ny=y+d[1];
                 //   cout<<nx<<ny<<endl;
                    if(nx>=0 and ny>=0 and nx<n and ny<m and vism[nx][ny]==-1 and adj[nx][ny]!='#'){
                        vism[nx][ny]=min;
                        qm.push({nx,ny}); 
                    }
                }
              }
              min++;

    }
    min=0;
  /* fi(i,0,n-1){
        fi(j,0,m-1){
            cout<<vism[i][j];
        }
        cout<<endl;
    }
   
    while(!q.empty())
{ 
     int s=q.size();
            
              for(int i=0;i<s;i++){
                int x=q.front().first,y=q.front().second;
                q.pop();
                if(x==0 or y==0 or x==n-1 or y==m-1)
                {
                    cout<<"YES"<<endl;

                    return 0;
                }
                qm.pop();
                 for(auto d:dir){
                    int nx=x+d[0],ny=y+d[1];
                     //   cout<<nx<<ny<<endl;
                     
                    if(nx>=0 and ny>=0 and nx<n and ny<m and vis[nx][ny]==-1 and adj[nx][ny]!='#' and vism[nx][ny]>min){
                        vis[nx][ny]=min;
                        q.push({nx,ny}); 
                    }
                }
              }
              min++;
   
}   

  */
   vector<char> ans;
    int sx=q.front().first,sy=q.front().second;
    
 dfs(sx,sy,0,'S',adj,vis,vism,ans);
 if(flag==false)   
cout<<"NO"<<endl;

    
    

}