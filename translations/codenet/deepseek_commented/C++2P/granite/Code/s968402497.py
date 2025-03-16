
import sys

tc, n, m = map(int, sys.stdin.readline().split())
if n > m:
    n, m = m, n

for i in range(1, m + 1):
    if n <= i * tc <= m:
        print("OK")
        exit(0)

print("NG")

