
import sys

N = 200
SHIRO = 0
HAI = 1
KURO = 2

def aaaaa():
    global n, A, color, d, f, TT
    n = int(input())
    A = [[0 for _ in range(n)] for _ in range(n)]
    color = [SHIRO for _ in range(n)]
    d = [0 for _ in range(n)]
    f = [0 for _ in range(n)]
    TT = 0
    for i in range(n):
        u, k = map(int, input().split())
        u -= 1
        for j in range(k):
            v = int(input())
            v -= 1
            A[u][v] = 1
    bbbbb(0)
    for i in range(n):
        print(f"{i+1} {d[i]} {f[i]}")

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

if __name__ == "__main__":
    aaaaa()

