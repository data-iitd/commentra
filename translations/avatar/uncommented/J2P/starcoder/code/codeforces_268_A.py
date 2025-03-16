
# <START-OF-CODE>
n = int(input())
h = [int(x) for x in input().split()]
g = [int(x) for x in input().split()]

result = 0
for i in range(n):
    for j in range(n):
        if h[i] == g[j]:
            result += 1

print(result)
# 