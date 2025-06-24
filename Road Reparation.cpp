
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int parent[N];
int sze[N];
void make(int v){
    parent[v]=v;
    sze[v]=1;
}
int find(int  v){
    if(parent[v]==v)return v;
    return parent[v]=find(parent[v]);
}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(sze[a]<=sze[b]){
            swap(a,b);
        }
        parent[b]=a;
        sze[a]+=sze[b];
    }
}
int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back({c, {a, b}});
    }
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    sort(edges.begin(), edges.end());
    int mst = 0;
    int cnt=0;
    for (auto it : edges)
    {
        int x = it.second.first;
        int y = it.second.second;
        if (find(x) != find(y))
        {
            Union(x, y);
            mst += it.first;
            cnt++;
        }
    }
    //cout<<cnt<<"   ";
    if(cnt!=n-1)cout<<"IMPOSSIBLE"<<endl;
   else  cout << mst << endl;
}
