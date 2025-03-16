
import sys

n = int(input())
h = list(map(int, input().split()))
g = list(map(int, input().split()))

result = 0

for i in range(n):
    for j in range(n):
        if h[i] == g[j]:
            result += 1

print(result)

# 