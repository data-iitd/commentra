import sys
import math
from bisect import bisect_left

def next_int():
    return int(sys.stdin.readline().strip())

def abs_val(x):
    return abs(x)

def min_val(x, y):
    return min(x, y)

def main():
    # Define a large constant for infinity
    INF = 10**11
    
    # Read the number of elements in the first array A and initialize it
    A = next_int()
    # Read the number of elements in the second array B
    B = next_int()
    # Read the number of queries Q
    Q = next_int()

    # Initialize the first array with boundary values
    s = [-INF] + [next_int() for _ in range(A)] + [INF]
    # Initialize the second array with boundary values
    t = [-INF] + [next_int() for _ in range(B)] + [INF]

    # Process each query
    for _ in range(Q):
        # Read the query value x
        x = next_int()
        # Find the position in the first array where x would fit
        b = bisect_left(s, x)
        d = bisect_left(t, x)
        # Initialize the result with infinity
        res = INF

        # Check the closest values in the first array
        for S in (s[b-1], s[b]):
            # Check the closest values in the second array
            for T in (t[d-1], t[d]):
                # Calculate the distances for both possible paths
                d1 = abs_val(S - x) + abs_val(T - S)
                d2 = abs_val(T - x) + abs_val(S - T)
                # Update the result with the minimum distance found
                res = min_val(res, min_val(d1, d2))

        # Output the result for the current query
        print(res)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
