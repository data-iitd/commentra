
import sys

N, K = map(int, sys.stdin.readline().split())
as = [0] * (N + 1)
for i in range(K):
    d = int(sys.stdin.readline())
    for j in range(d):
        a = int(sys.stdin.readline())
        as[a] += 1
ans = 0
for v in as:
    if v == 0:
        ans += 1
print(ans)

