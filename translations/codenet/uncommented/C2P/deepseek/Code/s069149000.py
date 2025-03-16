import sys

INF = 100000
MAX = 101
NIL = -6
WHITE = 0
GRAY = 1
BLACK = 2

G = [[INF] * MAX for _ in range(MAX)]
n = 0

def prim():
    d = [INF] * MAX
    pi = [NIL] * MAX
    color = [WHITE] * MAX
    min_val = INF
    u = NIL
    sum_ = 0

    d[0] = 0

    while True:
        min_val = INF
        u = NIL
        for i in range(n):
            if color[i] != BLACK and d[i] < min_val:
                min_val = d[i]
                u = i
        if u == NIL:
            break
        color[u] = BLACK
        for v in range(n):
            if color[v] != BLACK and G[u][v] != INF:
                if d[v] > G[u][v]:
                    d[v] = G[u][v]
                    pi[v] = u
                    color[v] = GRAY

    for i in range(n):
        if pi[i] != NIL:
            sum_ += G[i][pi[i]]

    print(sum_)

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())

    for i in range(n):
        row = list(map(int, sys.stdin.readline().strip().split()))
        for j in range(n):
            if row[j] == -1:
                G[i][j] = INF
            else:
                G[i][j] = row[j]

    prim()
