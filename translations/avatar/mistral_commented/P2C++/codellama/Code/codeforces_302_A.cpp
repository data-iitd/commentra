#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Define the number of strings n and the number of operations m
    int n, m;
    cin >> n >> m;

    // Calculate the number of '-' symbols in the input string
    int sa = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '-')
        {
            sa++;
        }
    }

    // Ensure the number of '-' symbols is valid
    sa = min(n - sa, sa);

    // Initialize an empty list 'ss' to store the results of each operation
    string ss;

    // Perform each operation as described in the problem statement
    for (int i = 0; i < m; i++)
    {
        // Read two integers a and b from the input
        int a, b;
        cin >> a >> b;

        // Calculate the difference between b and a
        b -= a;

        // Check if the difference is valid based on the number of '-' symbols
        if ((b % 2 == 0) || (b > sa << 1))
        {
            // If the difference is valid, add '1' to the result list 'ss'
            ss += "1\n";
        }
        // If the difference is not valid, add '0' to the result list 'ss'
        else
        {
            ss += "0\n";
        }
    }

    // Print the final result by joining all the strings in the 'ss' list with an empty string as separator
    cout << ss;

    return 0;
}

