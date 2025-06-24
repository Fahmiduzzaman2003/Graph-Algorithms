
#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
vector<bool> vis(N, false);
int cnt;
void dfs(int src){
    vis[src]=true;
    cnt++;
    for(auto it:adj[src]){
     if(!vis[it])dfs(it);
    }
}
int32_t main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

 cnt=0;
    bool ys=1;
  for(int i=1;i<=n;i++){
    if(adj[i].size()==2){
            continue;
    }
    else {
        ys=0;
        break;
    }
  }
dfs(1);
    if(ys&&cnt==n){
        cout << "Yes\n"; 
    }
    else{
        cout << "No\n";
    }
}
