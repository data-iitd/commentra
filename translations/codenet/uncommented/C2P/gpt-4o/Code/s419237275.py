N = 200
SHIRO = 0
HAI = 1
KURO = 2

def aaaaa():
    global TT
    for i in range(n):
        color[i] = SHIRO

    TT = 0

    for u in range(n):
        if color[u] == SHIRO:
            bbbbb(u)

    for i in range(n):
        print(i + 1, d[i], f[i])

def bbbbb(k):
    global TT
    color[k] = HAI
    TT += 1
    d[k] = TT
    for v in range(n):
        if A[k][v] == 0:
            continue
        if color[v] == SHIRO:
            bbbbb(v)
    color[k] = KURO
    f[k] = TT + 1
    TT += 1

n = int(input())
A = [[0] * N for _ in range(N)]
color = [0] * N
d = [0] * N
f = [0] * N
TT = 0

for i in range(n):
    u, k = map(int, input().split())
    u -= 1
    for j in range(k):
        v = int(input())
        v -= 1
        A[u][v] = 1

aaaaa()

# <END-OF-CODE>
