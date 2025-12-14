#include<bits/stdc++.h>
using namespace std;
#define ll            long long int
#define pii            pair<int,int>
#define ft             ios::sync_with_stdio(false);  cin.tie(NULL);
#define nl             "\n"
#define pb             push_back
#define py             cout<<"YES\n";
#define pn             cout<<"NO\n";
#define sz(x)          ((ll)(x).size())
#define all(x)            x.begin(),x.end()
#define vlowerB(v,x)   lower_bound(v.begin(),v.end(),x)
#define vupperB(v,x)   upper_bound(v.begin(),v.end(),x)
#define F              first
#define S              second
#define rep(i,a,b)     for(ll i=a;i<=b;i++)
#define rep2(i,b,a)    for(ll i=b;i>=a;i--)
#define vi             vector<ll>
#define countBit(x)      __builtin_popcountll(x)
#define zrbits(x)      __builtin_ctzll(x)
const ll MOD=1e9+7;
const ll N=2e5+9;
int dx[8] = { 1,0,-1,0,-1,1,-1,1 };
int dy[8] = { 0,1,0,-1,-1,1,1,-1 };
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
int lcm(int a,int b)
{
    return ((a/(__gcd(a,b)))*b);
}
bool comp(pair<int,int> &p1,pair<int,int> &p2)
{
    return p1.second<p2.second;
}
vi ans;
bool dfs(ll a,ll b){
    if(a>b){
        return false;
    }
    if(a==b){
        return true;
    }
    if(dfs(2*a,b))
    {
        ans.pb(2 * a);
        return true;
    }
   if(dfs(10*a+1,b))
    {
        ans.pb(10 * a + 1);
        return true;
    }
}
void solve(){
   ll a,b; cin>>a>>b;
   if(dfs(a,b)){
     ans.pb(a);
     reverse(all(ans));
     py
     cout<<sz(ans)<<nl;
     for(int x:ans) cout<<x<<" ";
   }
   else pn
}
int main()
{
   ft
   int t=1;
//    cin>>t;
   while(t--){
    solve();
   }
   
    return 0;
}