
import sys

N = int(sys.stdin.readline())
v = [0] * N

for i in range(1, N):
    a = int(sys.stdin.readline())
    v[a - 1] += 1

for e in v:
    print(e)

