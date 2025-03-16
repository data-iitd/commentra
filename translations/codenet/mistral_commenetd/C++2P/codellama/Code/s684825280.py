
import sys

n, k = map(int, sys.stdin.readline().split())

cnt = [0] * (1e5 * 2 + 13)

a = []

for i in range(n):
    x = int(sys.stdin.readline())
    cnt[x] += 1

for i in range(len(cnt)):
    if cnt[i] > 0:
        a.append(cnt[i])

a.sort()

m = len(a) - k

ans = 0

for i in range(m):
    ans += a[i]

print(ans)

