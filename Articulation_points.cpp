#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>adj[100005];
vector<bool>vis(100005),iscut(100005);
ll D[10000],low[100005];
ll timers=0;
void dfs(ll u,ll par){
    vis[u]=true;
    D[u]=low[u]=timers++;
    ll child=0;
    for(ll v:adj[u]){
        if(v==par) continue;
        if(vis[v]){
            // back edge
            low[u]=min(low[u],D[v]);
        }
        else{
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(par!=-1 && low[v]>=D[u]){
                iscut[u]=true;
            }
        }
        child++;
    }
    if(par==-1 && child>=2){
        iscut[u]=true;
    }
}
int main(){
    ll n,m; cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(ll i=1;i<=n;i++){
        if(!vis[i]) dfs(i,-1);
    }
    vector<ll>cuts;
    for(ll i=1;i<=n;i++){
        if(iscut[i]) {
            cout<<i<<" ";
        }
    }

   return 0;
}