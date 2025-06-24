
#include<bits/stdc++.h>
#define int long long 
using namespace std;
int32_t main(){
int n,m,q;
cin>>n>>m>>q;
int a[n][n];
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i==j){
            a[i][j]=0;
        }
       else a[i][j]=LLONG_MAX;
    }
}
for(int i=1;i<=m;i++){
    int x,y,c;
    cin>>x>>y>>c;
    x--;
    y--;
    a[x][y]=min(a[x][y],c);
    a[y][x]=min(a[y][x],c);


}
for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][k]!=LLONG_MAX&&a[k][j]!=LLONG_MAX)
            a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        }
    }
}
while(q--){
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    cout<<((a[x][y]!=LLONG_MAX)?(a[x][y]):(-1))<<endl;
}




}
