#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge;
    cin >> node >> edge;
    vector<vector<int>> adj_list(node);
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        bool edge_remove = false;
        for (int w : adj_list[v])
        {
            if (w == u)
            {
                edge_remove = true;
                break;
            }
        }
        if (!edge_remove)
        {
            adj_list[u].push_back(v);
        }
        else
        {
            edge--;
        }
    }

    int num_edges_removed = edge - adj_list.size();
    cout << "Number of edges removed: " << num_edges_removed << endl;

    return 0;
}

/*
input:
5 6

0 1
1 2
2 0
1 3
3 4
4 1

--------

*/