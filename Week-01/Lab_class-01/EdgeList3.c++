/*
Graph Representation:
**********************
Topic: Edge List:

0 ----1
     / \
    2---3
[
    [0,1]
    [1,2]
    [1,3]
    [2,3]
]

#if it is become weighted:

0 ----1
     / \
    2---3

    2
0 ----- 1

    4
1 ------ 2

    9
1 ------ 3

    1
2 ------ 3
[
    [0,1,2]
    [1,2,4]
    [1,3,9]
    [2,3,1]
]
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // For unweighted and undirected:
    //  int Nodes = 4;
    //  vector<vector<int>> edge_list;
    //  T.C -> O(E) [How much edge available]
    //  S.C -> O(E) [How much edge available]
    //  edge_list.push_back({0, 1});
    //  edge_list.push_back({1, 2});
    //  edge_list.push_back({1, 3});
    //  edge_list.push_back({2, 3});

    // for (int i = 0; i < edge_list.size(); i++)
    // {
    //     cout << edge_list[i][0] << " " << edge_list[i][1] << endl;
    // }
    //-----------------------------------------------------------

    // #you can do it using list initialization:
    // int Nodes = 4;
    // vector<vector<int>> edge_list = {
    //     {0, 1},
    //     {1, 2},
    //     {1, 3},
    //     {2, 3}};

    // for (int i = 0; i < edge_list.size(); i++)
    // {
    //     cout << edge_list[i][0] << " " << edge_list[i][1] << endl;
    // }

    //------------------------------------------------------------------------

    // #You can do for Weighted Graph:
    int Nodes = 4;
    vector<vector<int>> edge_list = {
        {0, 1, 2},
        {1, 2, 4},
        {1, 3, 9},
        {2, 3, 1}};

    for (int i = 0; i < edge_list.size(); i++)
    {
        cout << edge_list[i][0] << "--" << edge_list[i][1] << " | " << edge_list[i][2] << endl;
    }

    return 0;
}