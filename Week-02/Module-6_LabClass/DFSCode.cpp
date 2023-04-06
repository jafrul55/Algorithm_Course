#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

// Visited array:
int visited[N];
vector<int> adj_list[N];
/*
// adjacency_list
// vector<int> adj_list[N];
 adj_list[1]->2,4,5
 1 -- 2
 1 -- 4
 1 -- 5
*/
void dfs(int node)
{
    cout << node << endl;
    visited[node] = 1;
    // Loop adjacency node on adj_list[node]
    for (int adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
        {
            dfs(adj_node);
        }
    }
}

/*
Graph:
0 --- 1 --- 2 --- 3
      |     |
      |     |
      5-----4
#of nodes = 6
#of edges = 6

list of adj nodes ->
input:
6 6

0 1
1 2
2 3
1 5
2 4
5 4
----------------
#If I decrease one edge from graph:
Graph:
output:0,1,5,4,2,3
.     .
0 --- 1    .2--- 3.
      |     |
      |     |
     .5-----4.
#of nodes = 6
#of edges = 5

list of adj nodes ->
input:
6 5

0 1
2 3
1 5
2 4
5 4

*/
int main()
{
    // Now Graph input:
    int nodes, edges;
    cout << "Number of Node & Edge: " << endl;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int source = 0;
    dfs(source);

    return 0;
}