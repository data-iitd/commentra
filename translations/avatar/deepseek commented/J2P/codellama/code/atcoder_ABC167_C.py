import math
import sys

n, m, x = map(int, input().split())
a = []
for i in range(n):
    a.append(list(map(int, input().split())))

min = sys.maxsize
for i in range(int(math.pow(2, n))):
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

if min == sys.maxsize:
    print(-1)
else:
    print(min)

