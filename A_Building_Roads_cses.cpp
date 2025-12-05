#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define ft                                                                                                             \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(NULL);
#define nl "\n"
#define pb push_back
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define sz(x) ((ll)(x).size())
#define all(x) x.begin(), x.end()
#define vlowerB(v, x) lower_bound(v.begin(), v.end(), x)
#define vupperB(v, x) upper_bound(v.begin(), v.end(), x)
#define F first
#define S second
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define rep2(i, b, a) for (ll i = b; i >= a; i--)
#define vi vector<ll>
#define countBit(x) __builtin_popcountll(x)
#define zrbits(x) __builtin_ctzll(x)
const ll MOD = 1e9 + 7;
const ll N = 2e5 + 9;
int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
int lcm(int a, int b)
{
    return ((a / (__gcd(a, b))) * b);
}
bool comp(pair<int, int>& p1, pair<int, int>& p2)
{
    return p1.second < p2.second;
}
vi adj[N];
bool vis[N];
vi final;
void dfs(int src){
    vis[src]=true;
    for(int child:adj[src]){
        if(!vis[child]){
            dfs(child);
        }
    }
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    memset(vis,false,sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i]){
            final.pb(i);
            dfs(i);
        }
    }
    cout<<final.size()-1<<nl;
    for(int i=1;i<final.size();i++){
        cout<<final[0]<<" "<<final[i]<<nl;
    }
}
int main()
{
    ft int t = 1;
    //    cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}