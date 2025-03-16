
import sys

n = int(sys.stdin.readline())
a = [int(x) for x in sys.stdin.readline().split()]
b = []

for v in a:
    x = 0
    while x < len(b) and b[x] < v:
        x += 1
    if x == len(b):
        b.append(v)
    else:
        b[x] = v

print(len(b))

