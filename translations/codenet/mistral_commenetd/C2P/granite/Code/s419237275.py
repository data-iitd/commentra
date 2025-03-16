

import sys

N = 200
SHIRO = 0
HAI = 1
KURO = 2

def aaaaa():
    global n, A, color, d, f, TT
    for i in range(n):
        for j in range(n):
            A[i][j] = 0
    for i in range(n):
        print("Enter the number of neighbors for node {}: ".format(i+1), end="")
        k = int(input())
        for j in range(k):
            print("Enter the neighbor index: ", end="")
            v = int(input())
            A[i][v-1] = 1
    aaaaa()

def bbbbb(k):
    global n, A, color, d, f, TT
    color[k] = HAI
    TT += 1
    d[k] = TT
    for v in range(n):
        if A[k][v] == 1 and color[v] == SHIRO:
            bbbbb(v)
    color[k] = KURO
    f[k] = TT + 1

if __name__ == "__main__":
    n = int(input("Enter the number of nodes: "))
    A = [[0 for _ in range(N)] for _ in range(N)]
    color = [SHIRO for _ in range(N)]
    d = [0 for _ in range(N)]
    f = [0 for _ in range(N)]
    TT = 0
    aaaaa()
    for i in range(n):
        print("{} {} {}".format(i+1, d[i], f[i]))
        print("Node {} is visited at time {} and its finishing time is {}.".format(i+1, d[i], f[i]))

