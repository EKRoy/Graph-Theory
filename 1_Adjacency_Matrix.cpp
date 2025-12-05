#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,e; cin>>n>>e;
    int mat[n+1][n+1];
    memset(mat,0,sizeof(mat));
    while(e--){
         int u,v; cin>>u>>v;
        mat[u][v]=1;
        mat[v][u]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<'\n';
    }
   return 0;
}