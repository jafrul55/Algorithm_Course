// Calculate time and space complexity of the following code :

// int a = 0;
// for (i = 0; i < N; i++)
// {
//     for (j = N; j > i; j--)
//     {
//         a = a + i + j;
//     }
// }

/*
The time complexity of this code is O(N^2).
The outer loop iterates N times, and the inner loop iterates N−1 times on the first iteration, N−2 times on the second iteration, and so on.
The total number of iterations is the sum of the first N natural numbers, which is N(N+1)/2.
This simplifies to O(N^2) when we drop the lower order terms and constant factors.
The statement inside the loops is constant time and does not affect the overall time complexity.

The space complexity of this code is O(1),
since only a single integer variable a is used and its value is overwritten in each iteration of the loop.
 The space required for the loop variables i and j is also constant and does not affect the overall space complexity.








*/