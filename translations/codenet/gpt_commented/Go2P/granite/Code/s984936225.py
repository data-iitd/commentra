
import sys

N, M = map(int, input().split())

Inf = 1 << 62  # Using a large value for infinity, considering the maximum possible distance

a = [0] * M  # Array to store the starting vertices of edges
b = [0] * M  # Array to store the ending vertices of edges
c = [0] * M  # Array to store the weights of edges

for i in range(M):
    a[i], b[i], c[i] = map(int, input().split())
    c[i] = -c[i]  # Negate the weights for the algorithm (to handle maximization)

dist = [Inf] * N  # Array to store the minimum cost to reach each vertex
dist[0] = 0  # The starting vertex (0) has a distance of 0

for loop in range(N):
    for i in range(M):
        if dist[a[i] - 1] == Inf:
            continue
        if dist[b[i] - 1] > dist[a[i] - 1] + c[i]:
            dist[b[i] - 1] = dist[a[i] - 1] + c[i]

ans = dist[N - 1]  # The answer is the distance to the last vertex
navigate = [False] * N  # Array to track reachable vertices

for loop in range(N):
    for i in range(M):
        if dist[a[i] - 1] == Inf:
            continue
        if dist[b[i] - 1] > dist[a[i] - 1] + c[i]:
            dist[b[i] - 1] = dist[a[i] - 1] + c[i]
            navigate[b[i] - 1] = True  # Mark b[i] as reachable
        if navigate[a[i] - 1]:
            navigate[b[i] - 1] = True

if navigate[N - 1]:
    print("inf")  # If the last vertex is reachable, print "inf" (indicating a negative cycle)
else:
    print(-ans)  # Otherwise, print the negative of the answer (since weights were negated)

