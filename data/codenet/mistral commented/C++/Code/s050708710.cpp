
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
using ll = long long;
using P = pair<int, int>;

// Main function starts here
int main()
{
    int r, g, b, n; // Initialize variables for red, green, blue colors and number of balls

    // Read input values from standard input
    cin >> r >> g >> b >> n;

    int ans = 0; // Initialize answer variable to zero

    // Check all possible combinations of red, green and blue balls to find the answer
    for (int i = 0; i <= n / r; ++i) // Iterate through all possible combinations of red balls
    {
        for (int j = 0; j <= n / g; ++j) // Iterate through all possible combinations of green balls
        {
            int num = n - r * i - g * j; // Calculate the number of blue balls needed to make up the total number of balls

            // Check if the number of blue balls is valid (non-negative and divisible by b)
            if (num >= 0 && num % b == 0)
            {
                ++ans; // Increment the answer if the current combination is valid
            }
        }
    }

    // Print the answer to the standard output
    cout << ans << endl;

    // End of main function
    return 0;
}