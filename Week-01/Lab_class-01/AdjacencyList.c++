/*
Graph Representation:
**********************
Topic: Adjacency Matrix:

#no of nodes = 10
#no of adge = 2

0 --- 1
4 --- 5

Adj.Matrix
------------
matrix[0][1] = 1
matrix[1][0] = 1
matrix[4][5] = 1
matrix[5][4] = 1

n*n -> matrix
Time complexity -> O(n^2)
Space complexity -> O(n^2)

#Incase of Unweighted Graph:
----------------------------
#no of nodes = 10
#no of adge = 2

   2
0 --- 1

   9
4 --- 5

Adj.Matrix
------------
matrix[0][1] = 2
matrix[1][0] = 2
matrix[4][5] = 9
matrix[5][4] = 9

n*n -> matrix
Time complexity -> O(n^2)
Space complexity -> O(n^2)


#Incase of Undirected Graph:
------------------------------

#no of nodes = 10
#no of adge = 2

   2
0 ----> 1

    9
4 <---- 5

Adj.Matrix
------------
matrix[0][1] = 2
// matrix[1][0] = 0
// matrix[4][5] = 0
matrix[5][4] = 9

n*n -> matrix
Time complexity -> O(n^2)
Space complexity -> O(n^2)
-------------------------------
Topic: Adjacency List -> Linked List/ c++ Vector
#If directed graph:
0 ----1
      / \
     /   \
    2 ----3

0 -> 1
1 -> 2
3 -> 2
3 -> 1

adj_list[0] = {1};
adj_list[1] = {2};
adj_list[2] = {}
adj_list[3] = {1, 2};

#If weighted and directed graph:

0 ---- 1
      / \
     /   \
    2 ----3

    2
0 -----> 1

    4
1 ------> 2

    8
3 ------> 2

     7
3 ------> 1

0 -> 1
1 -> 2
3 -> 2
3 -> 1

adj_list[0] = {{1, 2}};
adj_list[1] = {{2, 4}};
adj_list[2] = {};
adj_list[3] = {{2, 8}, {1, 7}};

---------------------

if our graph become sparse(less edge) then it can
perform better:
Time Complexity -> O(E)
Space Complexity -> O(E)

 vector<int> adj_list[n]; //T.C -> O(1) Constant

//O(E) -> if #of edge is low
 adj[0] = {1}
 adj[1] = {0}
 adj[4] = {5}
 adj[5] = {4}

*/
#include <bits/stdc++.h>
using namespace std;
// Final Time Complexity =
// O(1) + O(n^2) + O(n^2)
// = O 2(n^2)
//    = O(n^2)

// Final Space Complexity =
//= O(1) + O(n) + O(n^2) + O(1)
//   = O(n^2)

/*
pair take two thing:
pair<string,double> variable_name;
pair<int,double>variable_name;

pair<int,int>variable_pair;

if want get value from pair
then:
variable_pair.first
variable_pair.second

*/

int main()
{
    // Time Complexity->O(1)
    // Space Complexity -> O(1)

    /*
     // T.C->O(1),Space Complexity->O(n)
    // Number of Edge: T.C --> O(E * 2)->O(E)->O(n^2);

    // Space Complexity ->O(E*2)->O(E) ->O(n^2)

    */

    // We will take a vector of array:
    // #If Graph become undirected:
    // int nodes = 4;
    // vector<int> adj_list[nodes];

    // adj_list[0] = {1};
    // adj_list[1] = {0, 2, 3};
    // adj_list[2] = {1, 3};
    // adj_list[3] = {1, 2};

    // for (int i = 0; i < nodes; i++)
    // {
    //     cout << i << "->";
    //     for (int j = 0; j < adj_list[i].size(); j++)
    //     {
    //         cout << adj_list[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    //---------------------------------------------------
    // #If Graph become Directed:
    // int nodes = 4;
    // vector<int> adj_list[nodes];
    // adj_list[0] = {1};
    // adj_list[1] = {2};
    // adj_list[2] = {};
    // adj_list[3] = {1, 2};

    // for (int i = 0; i < nodes; i++)
    // {
    //     cout << i << "-->";
    //     for (int j = 0; j < adj_list[i].size(); j++)
    //     {
    //         cout << adj_list[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    //---------------------------------------
    // Now we will use here a for Loop:
    // T.C -> O(E * 2) -> O(E) ->O(n^2)
    // Space_Complexity -> O(1)
    //--------------------------------------------------------
    // #But if your graph are Directed and Weighted:
    // We will use pair:
    int nodes = 4;
    vector<pair<int, int>> adj_list[nodes];
    // adj_list[0].push_back({1, 2});
    // adj_list[1].push_back({2, 4});
    // adj_list[3].push_back({2, 8});
    // adj_list[3].push_back({1, 7});
    // you can also do it using list initialization
    //  without using pushback:
    adj_list[0] = {{1, 2}};
    adj_list[1] = {{2, 4}};
    adj_list[2] = {};
    adj_list[3] = {{2, 8}, {1, 7}};

    for (int i = 0; i < nodes; i++)
    {
        cout << i << "->";
        for (int j = 0; j < adj_list[i].size(); j++)
        {
            cout << "(" << adj_list[i][j].first << " ," << adj_list[i][j].second << " )";
        }
        cout << endl;
    }

    return 0;
}