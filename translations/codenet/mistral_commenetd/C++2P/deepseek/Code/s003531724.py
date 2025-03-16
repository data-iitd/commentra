import sys
from collections import defaultdict

# Define a class to represent an edge in the graph
class Edge:
    def __init__(self, to, pre, c):
        self.to = to
        self.pre = pre
        self.c = c

# Define a function to insert an edge into the graph
def ins(a, b, c):
    global l
    e[l] = Edge(b, u[a], c)
    u[a] = l
    l += 1

# Define the main function to read the input and compute the answer
def main():
    global n, m, e, u, l
    # Read the input n and m, where n is the number of nodes and m is the number of edges
    n, m = map(int, sys.stdin.readline().split())
    # Initialize some variables and arrays
    ans = 0
    vis = [False] * (n + 1)
    d = [0] * (n + 1)
    cnt = [0, 0, 0]
    u = [-1] * (n + 1)
    e = [Edge(0, 0, 0)] * (2 * m + 1)
    l = 1

    # Read the edges of the graph
    for _ in range(m):
        a, b, c = map(int, sys.stdin.readline().split())
        ins(a, b, c % 3)
        ins(b, a, c % 3)

    # Perform a depth-first search for each unvisited node
    for i in range(1, n + 1):
        if not vis[i]:
            T = 0
            cnt = [0, 0, 0]
            ok = True
            dfs(i, 0)
            s = sum(cnt)
            # Compute the answer based on the information obtained during the depth-first search
            if not ok:
                ans += s * s
            else:
                if cnt[0] and cnt[1] and cnt[2]:
                    ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]
                else:
                    ans += T // 2

    # Output the answer and terminate the program
    print(ans)

# Define a function to perform a depth-first search of the graph
def dfs(x, l):
    vis[x] = True
    cnt[l] += 1
    d[x] = l
    i = u[x]
    while i != -1:
        T += 1
        if not vis[e[i].to]:
            dfs(e[i].to, (l + e[i].c) % 3)
        elif (l + e[i].c) % 3 != d[e[i].to]:
            ok = False
        i = e[i].pre

# Call the main function
if __name__ == "__main__":
    main()
