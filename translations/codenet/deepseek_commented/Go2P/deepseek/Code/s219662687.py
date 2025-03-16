import sys
import bisect
import math

def input():
    return sys.stdin.readline().strip()

INF = int(math.pow(10, 11))  # Define a large constant for infinity
A = int(input())  # Read the number of temples
B = int(input())  # Read the number of shrines
Q = int(input())  # Read the number of queries
s = [-INF] + [int(input()) for _ in range(A)] + [INF]  # Create a list for temples with extra space for boundaries
t = [-INF] + [int(input()) for _ in range(B)] + [INF]  # Create a list for shrines with extra space for boundaries

for _ in range(Q):
    x = int(input())  # Read the query point
    b = bisect.bisect_left(s, x)  # Find closest temples
    d = bisect.bisect_left(t, x)  # Find closest shrines
    res = INF  # Initialize result with infinity
    for S in [s[b-1], s[b]]:  # Check previous and current temple
        for T in [t[d-1], t[d]]:  # Check previous and current shrine
            d1 = abs(S - x) + abs(T - S)  # Calculate distances
            d2 = abs(T - x) + abs(S - T)  # Calculate distances
            res = min(res, min(d1, d2))  # Update result with minimum distance

    print(res)  # Print the minimum distance for the query
