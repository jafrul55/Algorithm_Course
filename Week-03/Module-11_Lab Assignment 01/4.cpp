#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int visited[N];
int parent[N];
vector<int> adj_list[N];

bool detect_cycle_undirected(int node)
{
    visited[node] = 1;
    for (int adj_node : adj_list[node])
    {
        if (adj_node == parent[node])
        {
            continue;
        }

        if (visited[adj_node] == 0)
        {
            parent[adj_node] = node;
            bool got_cycle = detect_cycle_undirected(adj_node);
            if (got_cycle)
            {
                return true;
            }
        }

        else if (visited[adj_node] == 1)
        {
            return true;
        }
    }

    visited[node] = 2;
    return false;
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

    bool cycle_exists = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            bool got_cycle = detect_cycle_undirected(i);
            if (got_cycle)
            {
                cycle_exists = true;
                break;
            }
        }
    }

    if (cycle_exists)
    {
        cout << "Cycle Exists" << endl;
    }
    else
    {
        cout << "Cycle Not Found" << endl;
    }

    return 0;
}

/*
input:
//Cycle exists:
5 6
1 3
1 2
5 3
1 5
2 4
4 5
Cycle not Exists:
5 4
2 1
1 3
3 5
5 4
*/