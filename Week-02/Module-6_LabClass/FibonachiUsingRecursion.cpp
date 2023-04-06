// Fibonacchi Number using Recursion:
/*
0,1,1,2,3,5,8,13,21...........
fibo(n) = f(n-1) + f(n-2)
problem:Calculate the n-th Fibonacchi Number

f(n)=?
f(0) = 0  | Base Case:
f(1) = 1  | f(0) = 0
f(2) = 1  | f(1) = 1
f(3) = 2  |
f(4) = 3  |
........  |
....so on

f(5) = f(4) + f(3)
f(6) = f(5) + f(4)
f(n) = f(n-1) + f(n-2)
*/
#include <bits/stdc++.h>
using namespace std;
// 0 , 1, 1, 2, 3, 5, 8, 13, 21.....>Fib number
// 0, 1, 2, 3, 4, 5, 6, 7, 8......>Index
int fibonacchi(int n)
{
    // Base case:
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // general Case:
    int num1 = fibonacchi(n - 1);
    int num2 = fibonacchi(n - 2);
    return num1 + num2;

    // you can also use it:
    // return fibonacchi(n - 1) + fibonacchi(n - 2);
}
int main()
{
    int n;
    cout << "Enter fibonacchi Number: ";
    cin >> n;
    cout << fibonacchi(n) << endl;

    return 0;
}