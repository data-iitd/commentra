import heapq

INF = 1000000

class Edge:
    def __init__(self, go, back, cost):
        self.go = go
        self.back = back
        self.cost = cost

def root(b):
    d = [INF] * n
    d[0] = 0
    pq = [(0, 0)]
    while pq:
        dist, u = heapq.heappop(pq)
        if dist > d[u]:
            continue
        for i in range(b):
            if a[i].back == u:
                v = a[i].go
                cost = a[i].cost
                if d[u] + cost < d[v]:
                    d[v] = d[u] + cost
                    heapq.heappush(pq, (d[v], v))
    return d

n = int(input())
a = []
for i in range(n):
    u, k = map(int, input().split())
    for j in range(k):
        go, cost = map(int, input().split())
        a.append(Edge(go, u, cost))

d = root(len(a))

for i in range(n):
    print(f"{i} {d[i]}")

