#include <iostream>
#include <vector>
#include <cmath> // for abs function

// Function to return the minimum of two integers
int chmin(int a, int b)
{
    if (a > b)
        return b; // Return b if it is smaller than a
    else
        return a; // Otherwise, return a
}

int main()
{
    int n;
    // Read the number of elements (n) from standard input
    std::cin >> n;
    
    // Declare vectors for dynamic programming and heights
    std::vector<int> dp(n, 10000); // dp[i] will hold the minimum cost to reach step i
    std::vector<int> h(n);  // h[i] will hold the height of step i

    // Read the heights of each step from standard input
    for (int i = 0; i < n; ++i)
        std::cin >> h[i];

    // Base case: the cost to reach the first step is 0
    dp[0] = 0;

    // Fill the dp vector with the minimum costs to reach each step
    for (int i = 1; i < n; ++i)
    {
        // Calculate the cost to reach step i from step i-1 and step i-2
        if (i == 1)
            dp[1] = std::abs(h[1] - h[0]); // Cost to jump from step 0 to step 1
        else
            // Choose the minimum cost between jumping from step i-1 or i-2
            dp[i] = chmin(dp[i - 1] + std::abs(h[i] - h[i - 1]), 
                          dp[i - 2] + std::abs(h[i] - h[i - 2]));
    }
    
    // Output the minimum cost to reach the last step
    std::cout << dp[n - 1] << std::endl;
    return 0; // End of the program
}

