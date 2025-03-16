
import sys

n, m, x = map(int, input().split())

p = [0] * n
a = [[0] * m for _ in range(n)]
for i in range(n):
    p[i] = int(input())
    a[i] = list(map(int, input().split()))

ans = 1200001
tot = 0
ok = True
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

if ans!= 1200001:
    print(ans)
else:
    print(-1)

