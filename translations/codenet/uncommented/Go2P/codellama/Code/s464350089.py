
import sys

h, n = map(int, sys.stdin.readline().split())
a = 0

for i in range(n):
    a += int(sys.stdin.readline())

if h > a:
    print("No")
else:
    print("Yes")

