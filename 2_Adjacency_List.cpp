#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> mat[n + 1];
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        mat[u].push_back(v);
        mat[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << "->";
        for (int x : mat[i])
        {
            cout << x << " ";
        }
        cout << '\n';
    }
    return 0;
}