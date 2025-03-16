/*depth first search
not lie in stack
*/
import sys

def dfs_visit(u):
    global color, d, f, tt
    color[u] = 1
    d[u] = tt
    tt += 1
    for v in range(n):
        if M[u][v] == 0:
            continue
        if color[v] == 0:
            dfs_visit(v)
    color[u] = 2
    f[u] = tt
    tt += 1

def dfs():
    global color, d, f, tt
    for i in range(n):
        color[i] = 0
    tt = 0
    for u in range(n):
        if color[u] == 0:
            dfs_visit(u)
    for i in range(n):
        print(i+1, d[i], f[i])

n = int(sys.stdin.readline())
M = [[0 for i in range(n)] for j in range(n)]
color = [0 for i in range(n)]
d = [0 for i in range(n)]
f = [0 for i in range(n)]
tt = 0
for i in range(n):
    k = int(sys.stdin.readline())
    u = i
    for j in range(k):
        v = int(sys.stdin.readline())
        M[u][v-1] = 1

dfs()

