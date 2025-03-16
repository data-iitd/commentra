
import sys

n = int(sys.stdin.readline())
a = list(map(float, sys.stdin.readline().split()))

while len(a) > 1:
    a.sort()
    na = []
    for i in range(2, len(a)):
        na.append(a[i])
    na.append((a[0] + a[1]) / 2)
    a = na

print(a[0])

