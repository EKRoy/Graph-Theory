#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> adj[100005];
ll n, K;
ll X;
ll cuts;
ll dfs(ll u, ll par)
{
    ll cur = 1;
    vector<ll> childsize;
    for (ll v : adj[u])
    {
        if (v == par)
            continue;
        childsize.push_back(dfs(v, u));
    }
    sort(childsize.begin(),childsize.end());
    for(ll s:childsize){
        if(cur+s>X) cuts++;
        else cur+=s;
    }
    return cur;
}
bool check(ll x)
{
    X = x;
    cuts = 0;
    ll rootpiece = dfs(1, -1);
    return cuts <= K;
}
int main()
{
    cin >> n >> K;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll l = 1, r = n, ans = n;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << '\n';
    return 0;
}