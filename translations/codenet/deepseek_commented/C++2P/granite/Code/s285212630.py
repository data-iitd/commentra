
# Import necessary libraries for input/output, data manipulation, and other functionalities
import sys
import math
import collections
import bisect
import heapq
import time
import random
import itertools
import string

# Define constants and data structures
MOD = 10**9 + 7
INF = float('inf')

# Read input and initialize the graph
def main():
    N = int(input())
    edges = [[] for _ in range(N)]
    for _ in range(N-1):
        a, b, c = map(int, input().split())
        a -= 1
        b -= 1
        edges[a].append((b, c))
        edges[b].append((a, c))

    # Perform depth-first search (DFS) to populate the ancestor matrix and rank array
    parent = [-1] * N
    depth = [0] * N
    cost = [0] * N
    stack = [(0, -1, 0)]
    while stack:
        v, p, d = stack.pop()
        if p >= 0:
            parent[v] = p
            depth[v] = d
            cost[v] = d
        for u, c in edges[v]:
            if u == p:
                continue
            stack.append((u, v, d + c))

    # Lowest Common Ancestor (LCA) function to find the lowest common ancestor of two nodes
    def lca(u, v):
        if depth[u] > depth[v]:
            u, v = v, u
        for k in range(20):
            if (depth[v] - depth[u]) >> k & 1:
                v = parent[v]
        if u == v:
            return u
        for k in range(19, -1, -1):
            if parent[u]!= parent[v]:
                u = parent[u]
                v = parent[v]
        return parent[u]

    # Distance calculation function to find the distance between two nodes
    def dist(u, v):
        l = lca(u, v)
        return cost[u] + cost[v] - 2 * cost[l]

    # Process queries
    Q, K = map(int, input().split())
    K -= 1
    for _ in range(Q):
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        print(dist(x, K) + dist(K, y))

if __name__ == '__main__':
    main()

