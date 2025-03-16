
import sys

n = int(sys.stdin.readline())
a = [int(sys.stdin.readline()) for _ in range(n)]
r = 0

for i in range(n):
    r ^= a[i]

for i in range(n):
    if i!= 0:
        print(" ", end="")
    print(r ^ a[i], end="")

# 