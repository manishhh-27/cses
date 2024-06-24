#include <bits/stdc++.h>
using namespace std;
int main(){
        int n;
        cin>>n;
        if(n==1){
            cout<<1;
            return 0;
        }
           if(n<=3){
            cout<<"NO SOLUTION";
            return 0;
           }
       
       int x=n/2;
       x++;
       
       for(int i=1;i<=n/2;i++){
        cout<<x<<" "<<i<<" ";
        x++;

       }
       if(n&1)
       cout<<n;


    return 0;
}