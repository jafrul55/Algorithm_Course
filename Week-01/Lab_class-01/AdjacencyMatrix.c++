/*
Graph Representation:
**********************
Topic: Adjacency Matrix:2D Array
A -> 0
B -> 1
C -> 2
D -> 3

A ---- B
      /\
     /  \
    C----D

Now we will replace it:
0 ---- 1
      /\
     /  \
    2----3

    #Total Nodes = 4
    #Total Edges = 4
    #Undirected + Unweighted

    Matrix -> #of nodes * of nodes
           -> 4 * 4 [row and col]

    matrix[i][j] = 1
    if and only if (i -> j)
0 -> 1
1 -> 0
1 -> 2
2 -> 1
2 -> 3
3 -> 2
3 -> 1
1 -> 3


0 1 0 0
1 0 1 1
0 1 0 1
0 1 1 0


*/
#include <bits/stdc++.h>
using namespace std;

// N = # of nodes

/*
#Adjacency Matrix:

#Time complexity:
  O(1) + O(1) + O(n^2) + O(n^2) = O(n^2)

#space complexity:
O(1) + O(n^2) = O(n^2)


*/
int main()
{
    int nodes = 4; // Time Complexity - O(1) and space complexity -> O(1)
    int matrix[nodes][nodes];

    // int matrix[nodes][nodes] = {};
    // Here time complexity will be->O(n ^ 2)
    // space complexity->O(n^2)
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            matrix[i][j] = 0;
        }
    }

    // O(E)   //E = mean number of edge ->n^2 ->O(n^2)

    matrix[0][1] = 1; // Time Complexity - O(1)
    matrix[1][0] = 1;

    matrix[1][2] = 1;
    matrix[2][1] = 1;

    matrix[2][3] = 1;
    matrix[3][2] = 1;

    matrix[3][1] = 1;
    matrix[1][3] = 1;

    // Time Complexity:O(n^2)

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}