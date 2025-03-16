
import sys

n = int(sys.stdin.readline())
a = list(map(float, sys.stdin.readline().split()))

for i in range(n-1):
    a.sort()
    na = []
    for j in range(2, len(a)):
        na.append(a[j])
    na.append((a[0] + a[1]) / 2)
    a = na

print(a[0])

