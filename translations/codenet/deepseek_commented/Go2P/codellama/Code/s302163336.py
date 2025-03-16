
import sys

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
h = list(map(int, sys.stdin.readline().split()))
good = [True] * n
for i in range(m):
    ai, bi = map(int, sys.stdin.readline().split())
    if h[ai - 1] > h[bi - 1]:
        good[bi - 1] = False
    elif h[ai - 1] < h[bi - 1]:
        good[ai - 1] = False
    else:
        good[ai - 1] = False
        good[bi - 1] = False
ans = 0
for i in range(n):
    if good[i]:
        ans += 1
print(ans)

