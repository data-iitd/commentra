
import sys

n, k = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))

a.sort()

ans = 0
for i in range(k, len(a)):
    ans += a[i]

print(ans)

