import bisect
import sys

# Define a large constant for infinity
INF = 10**11

# Read the number of elements in the first array A and initialize it
A = int(input())
# Read the number of elements in the second array B
B = int(int(input()))
# Read the number of queries Q
Q = int(input())

# Initialize the first array with boundary values
s = [-INF] + [int(input()) for _ in range(A)] + [INF]
# Initialize the second array with boundary values
t = [-INF] + [int(input()) for _ in range(B)] + [INF]

# Process each query
for _ in range(Q):
    # Read the query value x
    x = int(input())
    # Find the position in the first array where x would fit
    b = bisect.bisect_left(s, x)
    # Find the position in the second array where x would fit
    d = bisect.bisect_left(t, x)
    # Initialize the result with infinity
    res = INF

    # Check the closest values in the first array
    for S in [s[b-1], s[b]]:
        # Check the closest values in the second array
        for T in [t[d-1], t[d]]:
            # Calculate the distances for both possible paths
            d1, d2 = abs(S - x) + abs(T - S), abs(T - x) + abs(S - T)
            # Update the result with the minimum distance found
            res = min(res, min(d1, d2))

    # Output the result for the current query
    print(res)
