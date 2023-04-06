/*

Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3

Our TasK:
while there exists an empty cell:
    1.Find an empty unvisited cell
    2.run  bfs() from that cell

*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1000;

int maze[N][N], visited[N][N];
int n, m;

// Direction dx:

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return true;
    }
    return false;
}

bool is_safe(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;
    if (maze[x][y] == -1)
    {
        return false;
    }
    return true;
}

void bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    visited[src.first][src.second] = 1;

    q.push(src);

    while (!q.empty())
    {
        pair<int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair<int, int> adj_node = {new_x, new_y};

            if (is_inside(adj_node) &&
                is_safe(adj_node) &&
                visited[new_x][new_y] == 0)
            {
                // bfs
                visited[new_x][new_y] = 1;
                q.push(adj_node);
            }
        }
    }
}

pair<int, int> find_unvisited()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && maze[i][j] == 0)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++)
        {
            if (input[j] == '#')
            {
                maze[i][j] = -1;
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << maze[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // Infinity loop:

    int room_count = 0;
    while (true)
    {
        pair<int, int> unvisited_position = find_unvisited();
        if (unvisited_position == pair<int, int>(-1, -1))
        {
            break;
        }
        bfs(unvisited_position);
        room_count++;
    }
    cout << room_count << endl;

    return 0;
}