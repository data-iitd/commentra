import sys
from collections import defaultdict
from heapq import heappush, heappop
from math import sqrt
from itertools import permutations

# int -> long long
# vector<P> -> list of tuples
# rep(i, n) -> for i in range(n)
# _1 -> item[0]
# _2 -> item[1]
# INF -> float('inf')
# MOD -> 10**9 + 7
# MAX_L -> 22

# N: number of nodes, G: adjacency list, U: ancestor, R: depth, L: path length
N = 0
G = defaultdict(list)
U = [[0] * 100000 for _ in range(22)]
R = [0] * 100000
L = [0] * 100000

# Example usage
# N = 5
# G[0].append((1, 2))
# G[1].append((0, 2))
# G[2].append((3, 1))
# G[3].append((2, 1))
# G[4].append((5, 1))
# G[5].append((4, 1))

# Initialize U and R arrays
# for i in range(N):
#     U[0][i] = i
# for i in range(N):
#     R[i] = -1

# Function to add an edge to the graph
def add_edge(u, v, w):
    G[u].append((v, w))
    G[v].append((u, w))

# Function to preprocess the ancestors and depths
def preprocess():
    for i in range(1, MAX_L):
        for j in range(N):
            U[i][j] = U[i-1][U[i-1][j]]

# Function to find the k-th ancestor of a node
def kth_ancestor(node, k):
    for i in range(MAX_L):
        if k & (1 << i):
            node = U[i][node]
    return node

# Function to find the lowest common ancestor of two nodes
def lca(u, v):
    if R[u] < R[v]:
        u, v = v, u
    u = kth_ancestor(u, R[u] - R[v])
    if u == v:
        return u
    for i in range(MAX_L - 1, -1, -1):
        if U[i][u] != U[i][v]:
            u = U[i][u]
            v = U[i][v]
    return U[0][u]

# Main function to execute the code
def main():
    global N, G, U, R, L
    # Read input
    N = int(input())
    for _ in range(N - 1):
        u, v, w = map(int, input().split())
        add_edge(u, v, w)
    
    # Initialize U and R arrays
    for i in range(N):
        U[0][i] = i
        R[i] = -1
    
    # Preprocess the ancestors and depths
    preprocess()
    
    # Example usage of lca function
    # u, v = 2, 3
    # print(lca(u, v))

if __name__ == "__main__":
    main()
