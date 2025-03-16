#include <stdio.h>
#include <stdlib.h>

# Function to return the minimum of two integers
def chmin(a, b):
    if (a > b):
        return b; # Return b if it is smaller than a
    else:
        return a; # Otherwise, return a

def main():
    n = int(input()); # Read the number of elements (n) from standard input

    dp = [10000] * n; # Declare arrays for dynamic programming and heights
    h = [0] * n;

    for i in range(n):
        dp[i] = 10000; # Initialize the dp array with a large value (10000)

    for i in range(n):
        h[i] = int(input()); # Read the heights of each step from standard input

    dp[0] = 0; # Base case: the cost to reach the first step is 0

    for i in range(1, n):
        if (i == 1):
            dp[1] = abs(h[1] - h[0]); # Cost to jump from step 0 to step 1
        else:
            # Choose the minimum cost between jumping from step i-1 or i-2
            dp[i] = chmin(dp[i - 1] + abs(h[i] - h[i - 1]), 
                          dp[i - 2] + abs(h[i] - h[i - 2]));

    print(dp[n - 1]); # Output the minimum cost to reach the last step

main(); # End of the program

