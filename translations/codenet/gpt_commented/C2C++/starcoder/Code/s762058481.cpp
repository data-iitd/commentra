#include <iostream>
#include <cstdlib>

// Function to return the minimum of two integers
int chmin(int a, int b)
{
    if (a > b)
        return b; // Return b if it is smaller than a
    else
        return a; // Otherwise, return a
}

int main(int argc, char const *argv[])
{
    int n;
    // Read the number of elements (n) from standard input
    std::cin >> n;
    
    // Declare arrays for dynamic programming and heights
    int *dp = new int[n]; // dp[i] will hold the minimum cost to reach step i
    int *h = new int[n];  // h[i] will hold the height of step i
    
    // Initialize the dp array with a large value (10000)
    for (int i = 0; i < n; ++i)
        dp[i] = 10000;

    // Read the heights of each step from standard input
    for (int i = 0; i < n; ++i)
        std::cin >> h[i];

    // Base case: the cost to reach the first step is 0
    dp[0] = 0;

    // Fill the dp array with the minimum costs to reach each step
    for (int i = 1; i < n; ++i)
    {
        // Calculate the cost to reach step i from step i-1 and step i-2
        if (i == 1)
            dp[1] = abs(h[1] - h[0]); // Cost to jump from step 0 to step 1
        else
            // Choose the minimum cost between jumping from step i-1 or i-2
            dp[i] = chmin(dp[i - 1] + abs(h[i] - h[i - 1]), 
                          dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    
    // Output the minimum cost to reach the last step
    std::cout << dp[n - 1] << std::endl;
    return 0; // End of the program
}
