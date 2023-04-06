#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

// visited array:
int visited[N];
vector<int> adj_list[N];

void bfs(int src)
{
    queue<int> q;
    visited[src] = 1;
    q.push(src);
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        cout << head << endl;
        for (int adj_node : adj_list[head])
        {
            if (visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                q.push(adj_node);
            }
        }
    }
}

/*
Graph for bfs:
0 --- 1 --- 2 --- 3
      |     |
      |     |
      5-----4
#of nodes = 6
#of edges = 6

output--> 0,1,2,5,3,4
list of adj nodes ->
input:
6 6

0 1
1 2
2 3
1 5
2 4
5 4
---------------|
Graph for bfs:
#If I decrease one edge from graph:
0 --- 1     2 --- 3
      |     |
      |     |
      5-----4
#of nodes = 6
#of edges = 5

output--> 0,1,5,4,2,3
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
    int nodes, edges;
    cout << "Number of Nodes & Edges: " << endl;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src = 0;
    bfs(src);
    return 0;
}