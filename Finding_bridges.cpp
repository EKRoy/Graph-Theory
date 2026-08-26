#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>adj[100005];
vector<bool>vis(100005);
ll D[100005],low[100005];
ll timers=0;
vector<pair<ll,ll>>bridges;
void dfs(ll u,ll par){
    vis[u]=true;
    D[u]=low[u]=timers++;
    for(ll v:adj[u]){
        if(v==par) continue;
        if(vis[v]){
            // back edge
            low[u]=min(low[u],D[v]);
        }
        else{
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>D[u]){
                bridges.push_back({u,v});
            }

        }
    }
}
int main(){
    ll n,m ; cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(ll i=1;i<=n;i++){
        if(!vis[i]) dfs(i,-1);
    }
    cout<<bridges.size()<<'\n';
    for(auto [u,v]:bridges){
        cout<<u<<" "<<v<<'\n';
    }
   return 0;
}