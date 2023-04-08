#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int visited[N];
int level[N];
vector<int> adj_list[N];

void dfs(int source, int lev)
{
    visited[source] = 1;
    level[source] = lev;

    for (int adj_node : adj_list[source])
    {
        if (visited[adj_node] == 0)
        {
            dfs(adj_node, lev + 1);
        }
    }
}
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }
    int source = 0;
    int lev = 0;
    dfs(source, lev);
    for (int i = 0; i < nodes; i++)
    {
        cout << "Node " << i << "-->level: " << level[i] << endl;
    }

    return 0;
}

/*
Input as adJ_list and DAG:
6 5
0 1
1 2
2 3
2 4
4 5
---------
9 8
0 1
1 10
10 9
9 11
1 5
5 6
5 7
7 8

*/