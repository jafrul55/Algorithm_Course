#include <bits/stdc++.h>
using namespace std;
const int N = 202023;
vector<vector<int>> adj_list(N);
vector<vector<bool>> visited(N, vector<bool>(2, false));
vector<int> bridges;

void DFS(int node)
{
    visited[node][0] = true;
    for (auto adJ_node : adj_list[node])
    {
        if (visited[adJ_node][0] == false)
        {
            DFS(adJ_node);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i][0] == false)
        {
            bridges.push_back(i);
            DFS(i);
        }
    }

    cout << bridges.size() - 1 << endl;
    for (int i = 0; i < bridges.size() - 1; i++)
    {
        cout << bridges[i] << " " << bridges[i + 1] << endl;
    }

    return 0;
}
