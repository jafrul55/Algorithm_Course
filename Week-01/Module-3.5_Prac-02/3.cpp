// Calculate time and space complexity of the following code :

//     int a = 0,
//         i = N;
// vector<int> vec;
// while (i > 0)
// {
//     a += i;
//     i /= 2;
//     vec.push_back(a);
// }

/*
The time complexity of this code is O(log N), where N is the initial value of i.
The loop runs until i becomes 0, which occurs after log2(N) iterations.
In each iteration, the loop performs a constant number of operations (adding i to a, dividing i by 2, and appending a to the vector),
so the overall time complexity is O(log N).

The space complexity of this code is O(log N) as well.
 The vector vec grows logarithmically with the value of i,
so it will have log2(N) elements in the end.
The integer variables a and i require constant space and do not affect the overall space complexity.



*/
