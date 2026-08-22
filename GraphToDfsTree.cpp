#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>adj[100005];
bool vis[100005];
vector<pair<ll,ll>>tree_edges,back_edges;
void dfs(ll u,ll par){
    vis[u]=true;
    for(ll v:adj[u]){
        if(v==par) continue;
        if(!vis[v]){
            tree_edges.push_back({u,v});
            dfs(v,u);
        }
        else if(u<v){
            back_edges.push_back({u,v});
        }
    }
}
int main(){
    ll n,m; cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    cout<<"Tree edges:"<<'\n';
    for(auto [u,v]:tree_edges){
        cout<<u<<" "<<v<<'\n';
    }
    cout<<"Back edges: \n";
    for(auto [u,v]:back_edges){
        cout<<u<<" "<<v<<'\n';
    }
   return 0;
}