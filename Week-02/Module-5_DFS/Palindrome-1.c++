#include <bits/stdc++.h>
using namespace std;
/*
string= abcd
substr = bc

string = level -->5
substr = eve -->3
*/
bool is_palindrome(string str)
{
    // Base case:
    if (str == "" || str.size() == 1)
    {
        return true;
    }

    int n = str.size();
    string small_string = str.substr(1, n - 2);
    return is_palindrome(small_string) && (str[0] == str.back()); // Recursion
}
int main()
{
    string str;
    cout << "Enter Value: ";
    cin >> str;
    if (is_palindrome(str))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;
    return 0;
}