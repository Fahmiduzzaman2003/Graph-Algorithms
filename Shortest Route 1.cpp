
// SINGLE SOURCE SHORTEST PATH
#include <bits/stdc++.h>
using namespace std;
const int n = 2e5+5;
#define int long long 
vector<pair<int, int>> v[n];
int  dis[n];
class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
void dijsktra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    dis[src] = 0;
    while (!pq.empty())
    {
        pair<int, int> par = pq.top();
        pq.pop();
        int nod = par.second;
        int wt = par.first;
        if(wt>dis[nod])continue;//IMPORTANT
        for (auto child : v[nod])
        {
            int cnd = child.first;
            int cwt = child.second;
            if (wt + cwt < dis[cnd])
            {
                dis[cnd] = wt + cwt;
                pq.push({ wt + cwt,cnd});
            }
        }
    }
}

int32_t main()
{
      ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
     //   v[b].push_back({a, w});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
    }
    dijsktra(1);
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
}
