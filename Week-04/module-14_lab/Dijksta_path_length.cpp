#include <bits/stdc++.h>
using namespace std;
// n = 10^5
// m = 10^5

// max_w -> 10^6

// 10^6 * 10^5 -> 10^11
// O(ElogV)
//   1e9 mean = 10^9
//   you can also use long long infinity for 10e18
const int N = 1e5 + 5;
const long long INF = 1e18;
vector<pair<int, int>> adj_list[N];
// distance array
int visited[N];
int nodes, edges;

long long d[N];
/*
   w
u -----> v
  -----> x
    a
 u -> (v,w),(x,a)

*/
void dijkstra(int src)
{
    for (int i = 1; i <= nodes; i++)
    {
        d[i] = INF;
    }

    d[src] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        pair<long long, int> head = pq.top();
        pq.pop();
        // whose distance less we will select it= "int" less
        int selected_node = head.second;
        // if selected node already visited:
        if (visited[selected_node])
        {
            continue;
        }
        visited[selected_node] = 1;

        for (auto adj_entry : adj_list[selected_node])
        {
            int adj_node = adj_entry.first;
            int edge_cost = adj_entry.second;
            // if selected_node and edge_cost is less then adj_node
            if (d[selected_node] + edge_cost < d[adj_node])
            {
                // we will relax adj_node:
                d[adj_node] = d[selected_node] + edge_cost;
                // we will push adj_node->distance and adj_node
                // whose distance less he will stay up and we multiply(*(-1)):
                pq.push({-d[adj_node], adj_node});
            }
        }
    }
}
int main()
{

    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int src = 1;
    dijkstra(src);
    // This code will count the distance of the path/edges:
    cout << "Path distance: " << d[nodes] << endl;

    // for (int i = 1; i <= nodes; i++)
    // {
    //     cout << d[i] << " ";
    // }
    // cout << endl;

    return 0;
}