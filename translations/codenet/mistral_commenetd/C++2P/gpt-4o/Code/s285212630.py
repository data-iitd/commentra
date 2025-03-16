import sys
from collections import defaultdict
import math

# Constants
INF = 1145141919
MOD = 1000000007
MAX_L = 22

# N: number of nodes, G: adjacency list, U: ancestor, R: depth, L: path length
N = 0
G = defaultdict(list)
U = [[0] * 100000 for _ in range(MAX_L)]
R = [0] * 100000
L = [0] * 100000

# Helper functions can be added here

# Example of how to add edges to the graph
def add_edge(u, v):
    G[u].append((v, 0))  # Assuming weight is 0, modify as needed
    G[v].append((u, 0))  # Assuming undirected graph

# <END-OF-CODE>
