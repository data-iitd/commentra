import sys
import math
from bisect import bisect_left

def next_int():
    return int(sys.stdin.readline().strip())

def abs(x):
    return int(math.fabs(x))

def min(x, y):
    return int(math.fmin(x, y))

def max(x, y):
    return int(math.fmax(x, y))

def main():
    INF = 10**11
    A = next_int()
    B = next_int()
    Q = next_int()
    
    s = [-INF] + [next_int() for _ in range(A)] + [INF]
    t = [-INF] + [next_int() for _ in range(B)] + [INF]

    for _ in range(Q):
        x = next_int()
        b = bisect_left(s, x)
        d = bisect_left(t, x)
        res = INF
        
        for S in (s[b-1], s[b]):
            for T in (t[d-1], t[d]):
                d1 = abs(S - x) + abs(T - S)
                d2 = abs(T - x) + abs(S - T)
                res = min(res, min(d1, d2))

        print(res)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
