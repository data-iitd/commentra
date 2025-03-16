
#include <bits/stdc++.h>

using namespace std;

// Function to read a line of input
string input()
{
    string s;
    getline(cin, s);
    return s;
}

// Function to compute the ceiling of a divided by b
int ceil(int a, int b = 1)
{
    return -(-a / b);
}

// Function to round a number to the nearest integer
int round(double x)
{
    return (x * 2 + 1) / 2;
}

// Function to compute Fermat's little theorem for modular inverse
int fermat(int x, int y, int MOD)
{
    return x * pow(y, MOD - 2, MOD) % MOD;
}

// Function to compute the least common multiple of two numbers
int lcm(int x, int y)
{
    return (x * y) / __gcd(x, y);
}

// Function to compute the least common multiple of a list of numbers
int lcm_list(vector<int> nums)
{
    return accumulate(nums.begin(), nums.end(), 1, [](int a, int b) { return a * b / __gcd(a, b); });
}

// Function to read an integer from input
int INT()
{
    return stoi(input());
}

// Function to read a list of integers from input
vector<int> MAP()
{
    return vector<int>(istream_iterator<int>(cin), istream_iterator<int>());
}

// Function to read a list of integers into a list
vector<int> LIST()
{
    string s = input();
    vector<int> nums;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
            nums.push_back(s[i] - '0');
    }
    return nums;
}

// Set the maximum recursion limit
void set_recursion_limit(int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
        st.push(i);
    while (!st.empty())
        st.pop();
}

// Define constants for infinity and modulo
const int INF = 1e9;
const int MOD = 1e9 + 7;

// Read input values for costs of different types of drinks
int q, h, s, d;
cin >> q >> h >> s >> d;

// Read the number of drinks to be purchased
int n;
cin >> n;

// Calculate the best price for 1 liter of drink
int best1L = min(q * 4, h * 2, s);

// Calculate the best price for 2 liters of drink
int best2L = min(d, best1L * 2);

// Calculate and print the total cost based on whether n is even or odd
if (n % 2 == 0)
    cout << best2L * (n / 2) << endl; // Total cost for even number of drinks
else
    cout << best2L * (n / 2) + best1L << endl; // Total cost for odd number of drinks

