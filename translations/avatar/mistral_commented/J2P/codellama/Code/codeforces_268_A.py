
import sys

n = int(sys.stdin.readline())

h = list(map(int, sys.stdin.readline().split()))
g = list(map(int, sys.stdin.readline().split()))

result = 0

for i in range(n):
    for j in range(n):
        if h[i] == g[j]:
            result += 1

print(result)

