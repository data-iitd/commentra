#include <stdio.h>
#include <stdlib.h>

# Function to return the minimum of two integers
def chmin(a, b):
    if a > b:
        return b
    else:
        return a

def main(argc, argv):
    n = 0
    # Read the number of elements (n) from standard input
    scanf("%d", &n)
    
    # Declare arrays for dynamic programming and heights
    dp = [0] * n
    h = [0] * n
    
    # Initialize the dp array with a large value (10000)
    for i in range(n):
        dp[i] = 10000

    # Read the heights of each step from standard input
    for i in range(n):
        scanf("%d", &h[i])

    # Base case: the cost to reach the first step is 0
    dp[0] = 0

    # Fill the dp array with the minimum costs to reach each step
    for i in range(1, n):
        # Calculate the cost to reach step i from step i-1 and step i-2
        if i == 1:
            dp[1] = abs(h[1] - h[0]) # Cost to jump from step 0 to step 1
        else:
            # Choose the minimum cost between jumping from step i-1 or i-2
            dp[i] = chmin(dp[i - 1] + abs(h[i] - h[i - 1]), 
                          dp[i - 2] + abs(h[i] - h[i - 2]))
    
    # Output the minimum cost to reach the last step
    printf("%d\n", dp[n - 1])
    return 0 # End of the program

