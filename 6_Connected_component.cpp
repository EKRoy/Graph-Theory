#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1005];
bool vis[1005];
void dfs(int src){
   vis[src]=true;
//    cout<<src<<'\n';
   for(int child:adj[src]){
    if(!vis[child]){
        dfs(child);
    }
   }
}
int main(){
    int n,e; cin>>n>>e;
    while(e--){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src; cin>>src;
    memset(vis,false,sizeof(vis));
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt<<'\n';
   return 0;
}