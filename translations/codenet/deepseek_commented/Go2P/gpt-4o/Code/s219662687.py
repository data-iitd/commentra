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
    INF = 10**11  # Define a large constant for infinity
    A = next_int()  # Read the number of temples
    B = next_int()  # Read the number of shrines
    Q = next_int()  # Read the number of queries

    s = [-INF] + [next_int() for _ in range(A)] + [INF]  # Create a list for temples with boundaries
    t = [-INF] + [next_int() for _ in range(B)] + [INF]  # Create a list for shrines with boundaries

    for _ in range(Q):
        x = next_int()  # Read the query point
        b = bisect_left(s, x)  # Find closest temples
        d = bisect_left(t, x)  # Find closest shrines
        res = INF  # Initialize result with infinity

        for S in (s[b-1], s[b]):  # Check previous and current temple
            for T in (t[d-1], t[d]):  # Check previous and current shrine
                d1 = abs_val(S - x) + abs_val(T - S)  # Calculate distances
                d2 = abs_val(T - x) + abs_val(S - T)  # Calculate distances
                res = min_val(res, min_val(d1, d2))  # Update result with minimum distance

        print(res)  # Print the minimum distance for the query

if __name__ == "__main__":
    main()

# <END-OF-CODE>
