N = 200
SHIRO = 0
HAI = 1
KURO = 2

def aaaaa():
    for u in range(n):
        if color[u] == SHIRO:
            bbbbb(u)

    for i in range(n):
        print(f"{i + 1} {d[i]} {f[i]}")

def bbbbb(k):
    color[k] = HAI
    global TT
    TT += 1
    d[k] = TT
    for v in range(n):
        if A[k][v] == 0:
            continue
        if color[v] == SHIRO:
            bbbbb(v)
    color[k] = KURO
    TT += 1
    f[k] = TT

n = int(input())
A = [[0] * N for _ in range(N)]
color = [SHIRO] * N
d = [0] * N
f = [0] * N
TT = 0

for i in range(n):
    u, k = map(int, input().split())
    u -= 1
    for _ in range(k):
        v = int(input()) - 1
        A[u][v] = 1

aaaaa()
