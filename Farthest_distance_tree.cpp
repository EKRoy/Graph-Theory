#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>adj[100005];
ll mx_dist=-1,farthest_node;
vector<ll>dist(100005);
void dfs(ll u,ll par,ll d){
    dist[u]=d;
    if(d>mx_dist){
        mx_dist=d;
        farthest_node=u;
    }
    for(ll v:adj[u]){
        if(v==par) continue;
        dfs(v,u,d+1);
    }
}
int main(){
    ll n; cin>>n;
    for(ll i=0;i<n-1;i++){
        ll u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll R; cin>>R;
    dfs(R,-1,0);
    cout<<mx_dist<<'\n';
    cout<<farthest_node<<'\n';
    for(ll i=1;i<=n;i++){
        cout<<i<<"- "<<dist[i]<<'\n';
    }
   return 0;
}