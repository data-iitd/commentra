
import sys

# Global variables
N = 200
SHIRO = 0
HAI = 1
KURO = 2
n = 0
A = [[0 for _ in range(N)] for _ in range(N)]
color = [SHIRO for _ in range(N)]
d = [0 for _ in range(N)]
f = [0 for _ in range(N)]
TT = 0

# Function to perform depth-first search (DFS) and print discovery and finishing times
def aaaaa():
    global TT
    for i in range(n):
        if color[i] == SHIRO:
            bbbbb(i)
    for i in range(n):
        print(f"{i+1} {d[i]} {f[i]}")

# Recursive function to visit nodes in DFS
def bbbbb(k):
    global TT
    color[k] = HAI
    TT += 1
    d[k] = TT
    for v in range(n):
        if A[k][v] == 0:
            continue
        if color[v] == SHIRO:
            bbbbb(v)
    color[k] = KURO
    TT += 1
    f[k] = TT

# Read the number of nodes
n = int(input())

# Read the edges for each node
for i in range(n):
    u, k = map(int, input().split())
    u -= 1
    for j in range(k):
        v = int(input())
        v -= 1
        A[u][v] = 1

# Call the DFS function to process the graph
aaaaa()

print("