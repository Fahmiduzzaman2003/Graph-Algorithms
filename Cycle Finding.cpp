
#include<bits/stdc++.h>
using namespace std;

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> edgelist;
    int dis[2500];
    int par[2500];
    
    for (int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
        par[i] = -1;
    }
    
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edgelist.push_back({{x, y}, z});
    }
    
    dis[1] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (auto ed : edgelist) {
            int u = ed.first.first;
            int v = ed.first.second;
            int cost = ed.second;
            if (dis[u] < INT_MAX && dis[u] + cost < dis[v]) {
                dis[v] = dis[u] + cost;
                par[v] = u;
            }
        }
    }
    
   
    int x = -1;
    for (auto ed : edgelist) {
        int u = ed.first.first;
        int v = ed.first.second;
        int cost = ed.second;
        if (dis[u] < INT_MAX && dis[u] + cost < dis[v]) {
            x = v;
            break;
        }
    }
  
    
    if(x!=-1){
        vector<int>cycle;
        for(int i=1;i<=n;i++){
            x=par[x];
        }
        int y=x;
       
        while(true){
            cycle.push_back(y);
            y=par[y];
            cout<<y<<" ";
            if(y==x){
                cycle.push_back(x);
                break;
            }
        }
    
    
              reverse(cycle.begin(),cycle.end());
     
        
        cout << "YES" << endl;
        for (auto it : cycle) {
            cout << it << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
