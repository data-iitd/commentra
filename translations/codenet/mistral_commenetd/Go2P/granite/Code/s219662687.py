
# Python code translation
import sys
from bisect import bisect_left

# Reading input values from standard input
A, B, Q = map(int, input().split())
s = [-10**11] + [int(input()) for _ in range(A)] + [10**11]
t = [-10**11] + [int(input()) for _ in range(B)] + [10**11]

# Processing each query
for _ in range(Q):
    x = int(input())

    # Finding the indices b and d of array s and t respectively
    # where s[b] and t[d] are the smallest elements greater than x
    b, d = bisect_left(s, x), bisect_left(t, x)

    # Computing the minimum distance between x and any pair of elements S and T
    # from arrays s and t respectively
    res = 10**11
    for S in [s[b-1], s[b]]:
        for T in [t[d-1], t[d]]:
            # Computing the absolute difference between S and x, and T and S
            d1, d2 = abs(S-x), abs(T-S)

            # Updating the minimum distance if the current pair has a smaller distance
            res = min(res, min(d1, d2))

    # Printing the minimum distance for the current query
    print(res)

# Comment to indicate the end of the code
print("