MAX = 100
INF = 999999
NIL = -1
WHITE = 0
BLACK = 2

def prim(n, G):
    u = 0
    mincost = 0
    d = [INF] * n
    pi = [NIL] * n
    color = [WHITE] * n
    sum_cost = 0

    d[0] = 0
    while True:
        mincost = INF

        for i in range(n):
            if color[i] != BLACK and d[i] < mincost:
                mincost = d[i]
                u = i

        if mincost == INF:
            break

        color[u] = BLACK

        for v in range(n):
            if color[v] != BLACK and G[u][v] < d[v] and G[u][v] != -1:
                pi[v] = u
                d[v] = G[u][v]

    for i in range(n):
        if d[i] != INF:
            sum_cost += d[i]

    return sum_cost

if __name__ == "__main__":
    n = int(input())
    G = []
    for i in range(n):
        row = list(map(int, input().split()))
        G.append(row)

    print(prim(n, G))

# <END-OF-CODE>
