
import sys

n, m = map(int, sys.stdin.readline().split())
h = list(map(int, sys.stdin.readline().split()))
counter = {}
for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    if h[a-1] < h[b-1]:
        counter[a] = 1
    elif h[a-1] > h[b-1]:
        counter[b] = 1
    elif h[a-1] == h[b-1]:
        counter[a] = 1
        counter[b] = 1

print(n - len(counter))

