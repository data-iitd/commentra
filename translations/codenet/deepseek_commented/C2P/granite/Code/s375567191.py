
# Python code

import sys

def visit(u):
    global time
    color[u] = "gray"
    d[u] = time
    time += 1
    for i in range(n):
        if g[u][i] == 0:
            continue
        if color[i] == "white":
            visit(i)
    color[u] = "black"
    f[u] = time
    time += 1

def dfs():
    global time
    time = 0
    for i in range(n):
        if color[i] == "white":
            visit(i)
    for i in range(n):
        print(i + 1, d[i], f[i])

if __name__ == "__main__":
    n = int(input())
    g = [[0 for _ in range(n)] for _ in range(n)]
    d = [0 for _ in range(n)]
    f = [0 for _ in range(n)]
    color = ["white" for _ in range(n)]
    for _ in range(n):
        x, y = map(int, input().split())
        for _ in range(y):
            z = int(input())
            g[x - 1][z - 1] = 1
    dfs()

