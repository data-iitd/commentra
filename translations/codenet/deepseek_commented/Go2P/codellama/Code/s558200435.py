
import sys

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
b = []
for v in a:
    x = bisect.bisect(b, v)
    if x == len(b):
        b.append(v)
    else:
        b[x] = v
print(len(b))

