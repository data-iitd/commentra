# Depth First Search (DFS) implementation in Python

N = 100
WHITE = 0
GRAY = 1
BLACK = 2

M = [[0] * N for _ in range(N)]
n = 0
color = [WHITE] * N
d = [0] * N
f = [0] * N
tt = 0

def dfs_visit(u):
    global tt
    color[u] = GRAY
    tt += 1
    d[u] = tt
    for v in range(n):
        if M[u][v] == 0:
            continue
        if color[v] == WHITE:
            dfs_visit(v)
    color[u] = BLACK
    tt += 1
    f[u] = tt

def dfs():
    global tt
    for i in range(n):
        color[i] = WHITE
    tt = 0
    
    for u in range(n):
        if color[u] == WHITE:
            dfs_visit(u)
    
    for i in range(n):
        print(i + 1, d[i], f[i])

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        for j in range(n):
            M[i][j] = 0
    for i in range(n):
        u, k = map(int, input().split())
        u -= 1
        for j in range(k):
            v = int(input())
            v -= 1
            M[u][v] = 1
            
    dfs()

# <END-OF-CODE>
