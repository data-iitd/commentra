

import sys

# Read the first two integers from the standard input
N, K = map(int, sys.stdin.readline().split())

# Allocate an integer array of size N to store the input elements
S = list(map(int, sys.stdin.readline().split()))

# Initialize variables for calculating the answer
temp = 0
ans = 10000000000

# Check the special case when the size of the sliding window is 1
if K == 1:
    # Iterate through the array to find the minimum absolute value
    for i in range(N):
        temp = S[i] # Read the current element
        ans = min(abs(temp), ans) # Update the answer if necessary
    # Print the answer
    print(ans)
else:
    # Initialize variables for calculating the minimum and maximum elements in the sliding window
    min, max = 0, 0

    # Iterate through all possible positions of the sliding window
    for i in range(N - K + 1):
        # Find the minimum and maximum elements in the current sliding window
        min = S[i]
        max = S[i + K - 1]

        # Calculate the sum of the absolute values of the minimum and maximum elements
        # and update the answer if necessary
        if min < 0 and max > 0:
            temp = 2 * (abs(min)) + max
        else:
            temp = max(abs(min), abs(max))
        ans = min(ans, temp)
    # Print the answer
    print(ans)

# End of code
