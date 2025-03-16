
import sys

def out(*x):
    print(*x)

N, M = map(int, input().split())
n = [[] for _ in range(N)]
for _ in range(M):
    from_, to = map(int, input().split())
    n[from_-1].append(to-1)
    n[to-1].append(from_-1)

for i in range(N):
    out(len(n[i]))

