// Link:https://atcoder.jp/contests/dp/tasks/dp_d
#include <bits/stdc++.h>
using namespace std;
/*
1.state:Knapsacks(n,cap)->maximum profit
considering objects 1 to n and capacity = cap
2.recurrance:
   knapsack(n,cap) -> max {
                            val[n] + Knapsack(n-1,cap-wt[n]),
                            Knapsack(n-1,cap)
                            }
3.base_case:knapsack(0,x) = 0  |x = weight

*/
const int N = 102;
const int M = 1e5 + 5;
long long dp[N][M];
int wt[N], val[N];

long long Knapsack(int n, int cap)
{
    // 1.base case
    if (n == 0)
    {
        return 0;
    }

    // 2.if result is already calculated for this state return it
    if (dp[n][cap] != -1)
    {
        return dp[n][cap];
    }

    // capacity less than weight
    if (cap < wt[n])
    {
        int ans = Knapsack(n - 1, cap);
        dp[n][cap] = ans;
        return ans;
    }
    // if yes
    int ans1 = val[n] + Knapsack(n - 1, cap - wt[n]);
    // if no
    int ans2 = Knapsack(n - 1, cap);
    int ans = max(ans1, ans2);
    dp[n][cap] = ans;
    return ans;
}
int main()
{
    int n, cap;
    cin >> n >> cap;

    for (int i = 1; i <= n; i++)
    {
        cin >> wt[i] >> val[i];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= cap; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << Knapsack(n, cap) << endl;

    return 0;
}