#include <iostream>
#include <vector>
#include <cstdlib> // for abs

// Function to return the minimum of two integers
int chmin(int a, int b)
{
    // If 'a' is greater than 'b', return 'b'
    if (a > b)
        return b;
    // Otherwise, return 'a'
    else
        return a;
}

// Main function
int main()
{
    // Read the number of elements 'n' from the standard input
    int n;
    std::cin >> n;

    // Allocate memory for two vectors 'dp' and 'h' of size 'n'
    std::vector<int> dp(n, 10000);
    std::vector<int> h(n);

    // Read the height of each element from the standard input
    for (int i = 0; i < n; ++i)
        std::cin >> h[i];

    // Initialize the first element of 'dp' to 0
    dp[0] = 0;

    // Iterate through the array 'dp' from the second element to the last
    for (int i = 1; i < n; ++i)
    {
        // Calculate the cost to reach the current index 'i' from the previous index 'i - 1'
        if (i == 1)
            dp[1] = abs(h[1] - h[0]);
        // Calculate the minimum cost to reach the current index 'i' from the previous index 'i - 1' or the previous previous index 'i - 2'
        else
            dp[i] = chmin(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    // Print the minimum cost to reach the last index 'n - 1'
    std::cout << dp[n - 1] << std::endl;

    // Return 0 to indicate successful execution
    return 0;
}

// <END-OF-CODE>
