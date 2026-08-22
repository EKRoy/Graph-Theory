#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> adj[100005];
ll mx_dist = -1, farthest_node;
vector<ll> dist(100005);
void dfs(ll u, ll par, ll d)
{
    dist[u] = d;
    if (d > mx_dist)
    {
        mx_dist = d;
        farthest_node = u;
    }
    for (ll v : adj[u])
    {
        if (v == par)
            continue;
        dfs(v, u, d + 1);
    }
}
int main()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = INT_MIN;
    dfs(1, -1, 0);
    ll A = farthest_node;
    dfs(A, -1, 0);
    ll diameter = mx_dist;
    cout<<diameter<<'\n';

    return 0;
}