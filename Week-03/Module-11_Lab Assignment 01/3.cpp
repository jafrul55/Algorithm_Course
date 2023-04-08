#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int> adj_list[N];
int visited[N];
// Using BFS:
bool detect_cycle(int node)
{
    queue<int> q;
    q.push(node);

    visited[node] = 1;

    while (!q.empty())
    {
        int head = q.front();
        q.pop();

        for (int adj_node : adj_list[head])
        {
            if (visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                q.push(adj_node);
            }
            else if (visited[adj_node] == 1)
            {
                return true;
            }
        }

        visited[head] = 2;
    }
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
    }

    bool cycle_exists = false;
    for (int i = 1; i <= n; i++)
    {
        bool got_cycle = detect_cycle(i);
        if (got_cycle)
        {
            cycle_exists = true;
            break;
        }
    }

    if (cycle_exists)
    {
        cout << "Cycle Exists" << endl;
    }
    else
    {
        cout << "Cycle not Exists" << endl;
    }

    return 0;
}

/*
input:
//If it is cycle exist:
4 5
1 3
2 1
2 4
3 2
3 4
--------
if cycle not exists:
4 4
1 3
2 1
2 4
3 4

*/