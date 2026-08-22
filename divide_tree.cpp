#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> adj[100005];
ll sz[100005];
ll n;
ll best = LLONG_MAX;
void dfs(ll u, ll par)
{
    sz[u] = 1;
    for (ll v : adj[u])
    {
        if (v == par)
            continue;
        dfs(v, u);
        sz[u] += sz[v];
        best = min(best, max(sz[v], n - sz[v]));
    }
}
int main()
{
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    cout << best << '\n';
    for (ll i = 1; i <= n; i++)
    {
        cout << sz[i] << " ";
    }
    return 0;
}