
import sys

N = int(input())
v = [0] * N

for i in range(1, N):
    a = int(input())
    v[a-1] += 1

for e in v:
    print(e)

