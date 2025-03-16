#include <stdio.h>
#include <stdlib.h>

# Function to return the smaller value between two integers
def chmin(a, b):
	if (a > b):
		return b;
	else:
		return a;

def main(argc, argv):
	n = int(input());  # Read the number of elements
	dp = [10000] * n; # Declare the dp array
	h = [0] * n;      # Declare the h array
	for i in range(n):
		dp[i] = 10000; # Initialize the dp array to a large value

	for i in range(n):
		h[i] = int(input()); # Read the heights into the h array

	dp[0] = 0; # Starting point with no cost
	for i in range(1, n):
		if (i == 1):
			dp[1] = abs(h[1] - h[0]); # Cost to reach the first step
		else:
			dp[i] = chmin(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2])); # Calculate the minimum cost to reach the current step
	print(dp[n - 1]); # Print the minimum cost to reach the last step
	return 0;

