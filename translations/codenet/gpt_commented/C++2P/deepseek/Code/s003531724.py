import sys
from collections import defaultdict

# Constants
N = 100010

# Structure to represent an edge in the graph
class Edge:
    def __init__(self, to, pre, c):
        self.to = to
        self.pre = pre
        self.c = c

# Array to store the head of each vertex's adjacency list
u = [0] * N
l = 0

# Function to insert an edge into the graph
def ins(a, b, c):
    global l
    l += 1
    e[l] = Edge(b, u[a], c)
    u[a] = l

# Macros for accessing edge properties
def v(i):
    return e[i].to

def ec(i):
    return e[i].c

def reg(i, a):
    i = u[a]
    while i:
        yield i
        i = e[i].pre

# Global variables
n = 0
m = 0
vis = [False] * N
ok = True
cnt = [0] * 3
d = [0] * N
T = 0
e = [None] * (N << 1)

# Depth-first search function to traverse the graph
def dfs(x, l):
    vis[x] = True
    cnt[l] += 1
    d[x] = l
    T += 1
    for i in reg(i, x):
        if not vis[v(i)]:
            dfs(v(i), (l + ec(i)) % 3)
        elif (l + ec(i)) % 3 != d[v(i)]:
            ok = False

# Main function
def main():
    global n, m
    # Read the number of vertices and edges
    n, m = map(int, sys.stdin.readline().split())
    
    # Read edges and construct the graph
    for _ in range(m):
        a, b = map(int, sys.stdin.readline().split())
        ins(a, b, 1)
        ins(b, a, 2)

    ans = 0

    # Iterate through all vertices
    for i in range(1, n + 1):
        if not vis[i]:
            T = 0
            cnt = [0] * 3
            ok = True
            dfs(i, 0)
            s = sum(cnt)
            if not ok:
                ans += s * s
            else:
                if cnt[0] and cnt[1] and cnt[2]:
                    ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]
                else:
                    ans += T // 2

    # Output the final answer
    print(ans)

# Call the main function
main()
