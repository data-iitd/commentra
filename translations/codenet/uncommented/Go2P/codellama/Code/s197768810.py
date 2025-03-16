
import sys

n, m = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))
sum = 0
for i in range(m):
    sum += a[i]
if sum > n:
    print(-1)
    sys.exit(0)
print(n - sum)

