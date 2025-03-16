import sys
input = sys.stdin.readline

def out(x):
    print(x)

def get_int():
    return int(input().strip())

def get_string():
    return input().strip()

# Node :
class Node:
    def __init__(self):
        self.to = []

# Read the number of nodes (N) and the number of edges (M)
N, M = map(int, input().split())

# Initialize a list of Node with N elements
n = [Node() for _ in range(N)]

# Read M pairs of edges and populate the adjacency list for each node
for _ in range(M):
    from_, to = map(int, input().split())
    n[from_ - 1].to.append(to - 1)
    n[to - 1].to.append(from_ - 1)

# Print the size of the adjacency list for each node
for i in range(N):
    out(len(n[i].to))

