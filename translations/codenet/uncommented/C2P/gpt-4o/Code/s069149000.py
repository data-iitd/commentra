INF = 100000
MAX = 101
NIL = -6
WHITE = 0
GRAY = 1
BLACK = 2

G = [[0] * MAX for _ in range(MAX)]
n = 0

def prim():
    global n
    d = [INF] * MAX
    pi = [NIL] * MAX
    color = [WHITE] * MAX
    sum = 0

    d[0] = 0

    while True:
        min = INF
        u = NIL
        for i in range(n):
            if color[i] != BLACK and d[i] < min:
                min = d[i]
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
            sum += G[i][pi[i]]
    print(sum)

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        row = list(map(int, input().split()))
        for j in range(n):
            e = row[j]
            if e == -1:
                G[i][j] = INF
            else:
                G[i][j] = e

    prim()
# <END-OF-CODE>
