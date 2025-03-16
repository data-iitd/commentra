
n = int(input())
result = 0
h = []
g = []
for i in range(n):
    h.append(int(input()))
    g.append(int(input()))
for i in range(n):
    for j in range(n):
        if h[i] == g[j]:
            result += 1
print(result)
