
import sys

n, k = map(int, sys.stdin.readline().split())

if k <= (n+n%2)/2:
    print("YES")
else:
    print("NO")

