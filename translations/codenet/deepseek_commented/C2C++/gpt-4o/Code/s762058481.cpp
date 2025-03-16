#include <iostream>
#include <vector>
#include <cstdlib> // for abs

// Function to return the smaller value between two integers
int chmin(int a, int b)
{
    return (a > b) ? b : a;
}

int main()
{
    int n;
    std::cin >> n;  // Read the number of elements
    std::vector<int> dp(n, 10000); // Declare the dp vector and initialize to a large value
    std::vector<int> h(n);         // Declare the h vector

    for (int i = 0; i < n; ++i)
        std::cin >> h[i]; // Read the heights into the h vector

    dp[0] = 0; // Starting point with no cost
    for (int i = 1; i < n; ++i)
    {
        if (i == 1)
            dp[1] = abs(h[1] - h[0]); // Cost to reach the first step
        else
            dp[i] = chmin(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2])); // Calculate the minimum cost to reach the current step
    }
    std::cout << dp[n - 1] << std::endl; // Print the minimum cost to reach the last step
    return 0;
}

// <END-OF-CODE>
