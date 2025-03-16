
import sys

n = int(sys.stdin.readline())
x = int(sys.stdin.readline())
l = []
for i in range(n):
    l.append(int(sys.stdin.readline()))

tmpSum = 0
rs = 0
for i, v in enumerate(l):
    tmpSum += v
    if i >= n:
        rs = n
        break
    if tmpSum <= x:
        rs = i + 2
    else:
        break

print(rs)

