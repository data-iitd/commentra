#include <bits/stdc++.h>

using namespace std;

// Set up input reading methods for efficiency
#define read(type)       \
    vector<type> v;      \
    for (type x = 0; x;) \
    {                    \
        cin >> x;        \
        v.push_back(x);  \
    }
#define readline(type) \
    vector<type> v;    \
    for (type x = 0; x;) \
    {                    \
        cin >> x;        \
        v.push_back(x);  \
    }
#define readlines(type) \
    vector<type> v;     \
    for (type x = 0; x;) \
    {                    \
        cin >> x;        \
        v.push_back(x);  \
    }

// Set recursion limit to handle deep recursion cases
#define RECURSION_LIMIT 10000000

// Define constants for infinity and modulo operations
#define INF 1000000000
#define MOD 1000000007

int main()
{
    // Read input string
    string s;
    cin >> s;

    // Check if all characters in the string are the same
    if (s.size() == 1)
    {
        cout << 0 << endl;  // If true, print 0 and exit
        return 0;
    }

    // Count the occurrences of each character in the string
    map<char, int> a;
    for (char c : s)
    {
        a[c]++;
    }

    // Calculate the answer as twice the minimum frequency of any character
    int ans = INF;
    for (auto it : a)
    {
        ans = min(ans, it.second * 2);
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

