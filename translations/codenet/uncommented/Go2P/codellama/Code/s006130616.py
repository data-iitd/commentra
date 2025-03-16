
import sys

n, m, x = map(int, sys.stdin.readline().split())

a = []
p = []
for i in range(n):
    p.append(int(sys.stdin.readline()))
    a.append(list(map(int, sys.stdin.readline().split())))

ans = 1200001
tot = 0
ok = True
skill = [0] * m
for i in range(n):
    if (1 << i) & n:
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

