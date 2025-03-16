
import sys

n = int(sys.stdin.readline())

type = []
for i in range(n):
    x, l = map(int, sys.stdin.readline().split())
    type.append((x - l, x + l))

type.sort(key=lambda x: x[1])

ans = 1
r = type[0][1]
for i in range(1, n):
    if type[i][0] >= r:
        ans += 1
        r = type[i][1]

print(ans)

