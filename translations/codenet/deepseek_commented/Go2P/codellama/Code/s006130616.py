
import sys

n, m, x = map(int, sys.stdin.readline().split())

a = [[0] * m for _ in range(n)]
p = [0] * n
for i in range(n):
    p[i] = int(sys.stdin.readline())
    for j in range(m):
        a[i][j] = int(sys.stdin.readline())

ans = 1200001
for bits in range(1 << n):
    tot = 0
    ok = True
    skill = [0] * m
    for i in range(n):
        if (bits >> i) & 1 == 1:
            tot += p[i]
            for j in range(m):
                skill[j] += a[i][j]
    for v in skill:
        if v < x:
            ok = False
            break
    if ok:
        if ans > tot:
            ans = tot

if ans != 1200001:
    print(ans)
else:
    print("-1")

