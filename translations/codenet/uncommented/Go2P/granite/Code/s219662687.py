
import sys
import math

INF = int(math.pow(10, 11))

A, B, Q = map(int, input().split())
s = [-INF] + [int(input()) for _ in range(A)] + [INF]
t = [-INF] + [int(input()) for _ in range(B)] + [INF]

for _ in range(Q):
    x = int(input())
    b, d = min(b for b, si in enumerate(s) if si >= x), min(d for d, ti in enumerate(t) if ti >= x)
    res = INF
    for S in [s[b-1], s[b]]:
        for T in [t[d-1], t[d]]:
            d1, d2 = abs(S-x) + abs(T-S), abs(T-x) + abs(S-T)
            res = min(res, min(d1, d2))
    print(res)

