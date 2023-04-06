#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 0, b = 0;
    int M, N;
    int matrix[N][M];
    for (int i = 0; i < N; i++)
    {
        a = a + i;
        matrix[i][i] = a;
    }

    for (int j = 0; j < M; j++)
    {
        b = b + 2 * j;
    }
}
/*
// Time Complexity: O(N+M)
The time complexity of this code snippet is O(N+M), where N is the number of rows and M is the number of columns in the matrix.
This is because the first for-loop runs N times and the second for-loop runs M times, giving a total of N+M iterations.
The statements inside the loops are constant time operations and do not affect the overall time complexity.

// Space Complexity: O(N*M)
The space complexity of this code snippet is O(N*M) since it creates a 2D matrix with N rows and M columns.
The integer variables a and b are constant space and do not affect the overall space complexity.

*/
