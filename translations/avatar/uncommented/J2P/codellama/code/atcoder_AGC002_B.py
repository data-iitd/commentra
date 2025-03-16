
import sys

N, M = map(int, sys.stdin.readline().split())

B = [Box(1, True)]

for i in range(1, N):
    B.append(Box(1, False))

for i in range(M):
    x, y = map(int, sys.stdin.readline().split())
    B[x-1].moveTo(B[y-1])

counter = 0

for b in B:
    if b.red:
        counter += 1

print(counter)

