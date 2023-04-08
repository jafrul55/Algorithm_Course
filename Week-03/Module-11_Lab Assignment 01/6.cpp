#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m;
vector<int> adj_list[N];
int indegree[N];

void topsort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> result;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        result.push_back(curr);

        for (int adj_node : adj_list[curr])
        {
            indegree[adj_node]--;
            if (indegree[adj_node] == 0)
            {
                q.push(adj_node);
            }
        }
    }
    if (result.size() != n)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        indegree[v]++;
    }
    topsort();
    return 0;
}
