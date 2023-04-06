#include <bits/stdc++.h>
using namespace std;
string int_to_binary(int decimal)
{
    if (decimal == 0)
    {
        return "";
    }
    else
    {
        if (decimal % 2 == 0)
        {
            return "0" + int_to_binary(decimal / 2);
        }
        else
        {
            return "1" + int_to_binary(decimal / 2);
        }
    }
}
int main()
{
    int decimal;
    cin >> decimal;
    cout << int_to_binary(decimal) << endl;

    return 0;
}