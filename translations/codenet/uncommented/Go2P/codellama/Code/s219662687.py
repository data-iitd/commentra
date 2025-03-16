
import sys
import math

def main():
    INF = int(math.pow(10, 11))
    A = int(sys.stdin.readline())
    B = int(sys.stdin.readline())
    Q = int(sys.stdin.readline())
    s = [-INF] + [int(sys.stdin.readline()) for _ in range(A)] + [INF]
    t = [-INF] + [int(sys.stdin.readline()) for _ in range(B)] + [INF]

    for i in range(Q):
        x = int(sys.stdin.readline())
        b, d = bisect_left(s, x), bisect_left(t, x)
        res = INF
        for S in [s[b-1], s[b]]:
            for T in [t[d-1], t[d]]:
                d1, d2 = abs(S-x)+abs(T-S), abs(T-x)+abs(S-T)
                res = min(res, min(d1, d2))

        print(res)

def bisect_left(a, x):
    lo, hi = 0, len(a)
    while lo < hi:
        mid = (lo + hi) // 2
        if a[mid] < x:
            lo = mid + 1
        else:
            hi = mid
    return lo

if __name__ == '__main__':
    main()

