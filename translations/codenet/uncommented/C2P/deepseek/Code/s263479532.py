import sys

def prim(graph, n):
    INF = float('inf')
    NIL = -1
    WHITE = 0
    BLACK = 2
    
    d = [INF] * n
    pi = [NIL] * n
    color = [WHITE] * n
    sum_ = 0
    
    d[0] = 0
    while True:
        mincost = INF
        u = -1
        
        for i in range(n):
            if color[i] != BLACK and d[i] < mincost:
                mincost = d[i]
                u = i
        
        if mincost == INF:
            break
        
        color[u] = BLACK
        
        for v in range(n):
            if color[v] != BLACK and graph[u][v] < d[v] and graph[u][v] != -1:
                pi[v] = u
                d[v] = graph[u][v]
    
    for i in range(n):
        if d[i] != INF:
            sum_ += d[i]
    
    return sum_

# Read input
n = int(input().strip())
graph = [[-1 if x == '-1' else int(x) for x in input().strip().split()] for _ in range(n)]

# Call prim's function and print the result
print(prim(graph, n))
