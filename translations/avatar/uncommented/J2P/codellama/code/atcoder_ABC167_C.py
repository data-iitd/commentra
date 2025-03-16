
import math
import sys

n, m, x = map(int, sys.stdin.readline().split())
a = [[0] * (m + 1) for _ in range(n)]
for i in range(n):
    for j in range(m + 1):
        a[i][j] = int(sys.stdin.readline())

min = 1000000000
for i in range(pow(2, n)):
    status = [0] * n
    for j in range(n):
        if (i >> j) & 1:
            status[j] = 1
    res = [0] * (m + 1)
    for j in range(n):
        if status[j]:
            for k in range(m + 1):
                res[k] += a[j][k]
    flag = True
    for j in range(1, m + 1):
        if res[j] < x:
            flag = False
            break
    if flag:
        min = min(min, res[0])
if min == 1000000000:
    print(-1)
else:
    print(min)

