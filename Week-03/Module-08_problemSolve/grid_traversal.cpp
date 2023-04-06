/*
Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########

Ouput-> 9

forbiden = # -> -1
. -> 0

Here x,y is cordinate

(5,6) --->right --->(5,7)
(5,6) --->left --->(5,5)
(5,6) --->up --->(4,6)
(5,6) --->down ---> (6,6)

(x,y) -> right ->(x,y+1)
(x,y) -> left ->(x,y-1)
(x,y) -> up ->(x-1,y)
(x,y) -> down ->(x+1,y)

#Check:
1.is the cell within the maze
2.is the cell forbidden/wall?
3.is the cell visited?

x y
- -
0  1
0 -1
-1 0
1  0

difference of x and y:
direction array:
dx[] = {0,0,-1,1}
dy[] = {1,-1,0,0}

for(int i=0;i<4;i++)
{
    int new_x = x + dx[i];
    int new_y = y + dy[i];
}

*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2002;

int maze[N][N], visited[N][N];
int level[N][N];
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
    level[src.first][src.second] = 0;

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
                level[new_x][new_y] = level[x][y] + 1;
                q.push(adj_node);
            }
        }
    }
}
int main()
{
    cin >> n >> m;

    pair<int, int> src, dest; // cordinate i, j
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            level[i][j] = -1;
        }
    }
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
            else if (input[j] == 'A')
            {
                src = {i, j};
            }
            else if (input[j] == 'B')
            {
                dest = {i, j};
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

    // BFS:
    bfs(src);

    if (level[dest.first][dest.second] == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << level[dest.first][dest.second] << endl;
    }

    return 0;
}