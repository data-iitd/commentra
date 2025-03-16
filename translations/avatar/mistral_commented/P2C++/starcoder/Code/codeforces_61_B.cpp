#include <bits/stdc++.h>
using namespace std;

// Function to check if given indices are valid
bool valid(int i, int j, int n, int m)
{
    if (i < n && i >= 0 && j >= 0 && j < m)
        return true;
    return false;
}

// Function to calculate sum of first n natural numbers
int sumn(int i, int n)
{
    return (n - i) * (i + n) / 2;
}

// Function to calculate square root of a number using quadratic formula
int sqfun(int a, int b, int c)
{
    return (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
}

// Function to read a single line as a tuple of integers
tuple<int, int, int> value()
{
    int a, b, c;
    cin >> a >> b >> c;
    return make_tuple(a, b, c);
}

// Function to read a single line as a list of integers
vector<int> values()
{
    int a, b, c;
    cin >> a >> b >> c;
    return {a, b, c};
}

// Function to read a single integer
int inp()
{
    int a;
    cin >> a;
    return a;
}

// Function to read a single integer from the standard input as a string
string instr()
{
    string a;
    cin >> a;
    return a;
}

// Function to read a list of integers
vector<int> inlst()
{
    int a, b, c;
    cin >> a >> b >> c;
    return {a, b, c};
}

// Function to read a list of integers from the standard input
vector<int> inlsts()
{
    int a, b, c;
    cin >> a >> b >> c;
    return {a, b, c};
}

// Function to read a single integer from the standard input
int inp()
{
    int a;
    cin >> a;
    return a;
}

// Function to read a single integer from the standard input
int inps()
{
    int a;
    cin >> a;
    return a;
}

// Function to read a single string from the standard input
string instr()
{
    string a;
    cin >> a;
    return a;
}

// Function to convert a string to a list
vector<char> stlst()
{
    string a;
    cin >> a;
    return {a.begin(), a.end()};
}

// Main function to solve the problem
int main()
{
    int t = inp();
    for (int i = 0; i < t; i++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        vector<string> l = {a, b, c};
        vector<string> p;
        do
        {
            p.push_back(a + b + c);
        } while (next_permutation(l.begin(), l.end()));
        string s;
        cin >> s;
        if (find(p.begin(), p.end(), s)!= p.end())
            cout << "ACC" << endl;
        else
            cout << "WA" << endl;
    }
    return 0;
}

