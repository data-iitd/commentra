
import sys

ns = list(map(int, sys.stdin.readline().split()))
ns.sort()
if ns == [1, 4, 7, 9]:
    print("YES")
else:
    print("NO")
