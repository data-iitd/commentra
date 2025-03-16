
import sys
import math

n = int(sys.stdin.readline().strip())
a = list(map(int, sys.stdin.readline().strip().split()))
r = []
m = 0

for i in range(1, n):
    if math.fabs(a[m]) > math.fabs(a[i]):
        m = i

for i in range(n):
    if a[m] >= 0 ^ a[i] >= 0:
        r.append(str(m + 1) + " " + str(i + 1))

if a[m] >= 0:
    for i in range(1, n):
        r.append(str(i) + " " + str(i + 1))
else:
    for i in range(n, 1, -1):
        r.append(str(i) + " " + str(i - 1))

print(len(r))
for i in r:
    print(i)

