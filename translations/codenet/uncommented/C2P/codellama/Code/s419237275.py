#include <stdio.h>

#define N 200
#define SHIRO 0
#define HAI 1
#define KURO 2

def aaaaa():
    global n,A,color,d,f,TT

    for i in range(n):
        color[i] = SHIRO

    TT = 0

    for u in range(n):
        if color[u] == SHIRO:
            bbbbb(u)

    for i in range(n):
        print(i+1,d[i],f[i])

def bbbbb(k):
    global n,A,color,d,f,TT

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

n = int(input())

A = [[0 for i in range(N)] for j in range(N)]
color = [SHIRO for i in range(N)]
d = [0 for i in range(N)]
f = [0 for i in range(N)]
TT = 0

for i in range(n):
    u,k = map(int,input().split())
    u -= 1
    for j in range(k):
        v = int(input())
        v -= 1
        A[u][v] = 1

aaaaa()

