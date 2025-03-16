n = int(input())
result = 0
h = [0] * n
g = [0] * n

for i in range(n):
    h[i], g[i] = map(int, input().split())

for i in range(n):
    for j in range(n):
        if h[i] == g[j]:
            result += 1

print(result)
# <END-OF-CODE>
