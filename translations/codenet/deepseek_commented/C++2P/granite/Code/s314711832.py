
import sys

def min(a, b):
    if a < b:
        return a
    else:
        return b

def dijkstra(V, E, r):
    edges = []
    for i in range(E):
        source, target, weight = map(int, input().split())
        edges.append((source, target, weight))

    distances = [sys.maxsize] * V
    distances[r] = 0

    for i in range(V-1):
        prev_distances = distances.copy()
        for source, target, weight in edges:
            distances[target] = min(distances[source] + weight, distances[target])
        if distances == prev_distances:
            break

    for i in range(V):
        if distances[i] == sys.maxsize:
            print("INF")
        else:
            print(distances[i])

V, E, r = map(int, input().split())
dijkstra(V, E, r)
