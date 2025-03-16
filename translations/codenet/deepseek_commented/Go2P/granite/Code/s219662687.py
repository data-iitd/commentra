
import sys
from bisect import bisect_left
from math import inf

def main():
    A, B, Q = map(int, input().split())
    s = [-inf] + [int(input()) for _ in range(A)] + [inf]
    t = [-inf] + [int(input()) for _ in range(B)] + [inf]
    for _ in range(Q):
        x = int(input())
        b, d = bisect_left(s, x), bisect_left(t, x)
        res = inf
        for S in [s[b-1], s[b]]:
            for T in [t[d-1], t[d]]:
                d1, d2 = abs(S-x) + abs(T-S), abs(T-x) + abs(S-T)
                res = min(res, min(d1, d2))
        print(res)

if __name__ == "__main__":
    main()

