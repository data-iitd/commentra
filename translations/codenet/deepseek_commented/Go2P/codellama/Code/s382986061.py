
import sys

N, K = map(int, sys.stdin.readline().split())
as = [0] * (N + 1)
for i in range(K):
    d = int(sys.stdin.readline())
    for j in range(d):
        a = int(sys.stdin.readline())
        as[a] += 1
ans = 0
for i in range(1, N + 1):
    if as[i] == 0:
        ans += 1
print(ans)

