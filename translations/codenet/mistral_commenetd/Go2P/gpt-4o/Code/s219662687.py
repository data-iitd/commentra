import sys
import math
from bisect import bisect_right

# Constants
INF = int(math.pow(10, 11))

def next_int():
    return int(sys.stdin.readline().strip())

def abs_val(x):
    return abs(x)

def min_val(x, y):
    return min(x, y)

def main():
    # Reading input values
    A = next_int()
    B = next_int()
    Q = next_int()

    # Initializing arrays s and t
    s = [-INF] + [next_int() for _ in range(A)] + [INF]
    t = [-INF] + [next_int() for _ in range(B)] + [INF]

    # Processing each query
    for _ in range(Q):
        x = next_int()

        # Finding the indices b and d
        b = bisect_right(s, x)
        d = bisect_right(t, x)

        # Computing the minimum distance
        res = INF
        for S in (s[b-1], s[b]):
            for T in (t[d-1], t[d]):
                d1 = abs_val(S - x)
                d2 = abs_val(T - S)
                res = min_val(res, min_val(d1, d2))

        # Printing the minimum distance for the current query
        print(res)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
