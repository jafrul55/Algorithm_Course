#include <bits/stdc++.h>

/*
0---->1------>3
^    /^      /
|  /   \    /
| V     \  v
2         4

5 6

0 1
1 2
2 0
1 3
3 4
4 1
-------------
Bidirectional graph:
4 8

0 1
1 0
1 2
2 1
1 3
3 1
2 3
3 2


*/
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }

    bool is_bidirectional = true;
    for (int u = 0; u < n; u++)
    {
        for (int v : adj_list[u])
        {
            bool reverse_edge_found = false;
            for (int w : adj_list[v])
            {
                if (w == u)
                {
                    reverse_edge_found = true;
                    break;
                }
            }

            if (!reverse_edge_found)
            {
                is_bidirectional = false;
                break;
            }
        }
        if (!is_bidirectional)
        {
            break;
        }
    }

    if (is_bidirectional)
    {
        cout << "The graph is bi-directional\n";
    }
    else
    {
        cout << "The graph is not bi-directional\n";
    }

    return 0;
}