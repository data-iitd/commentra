import sys
from collections import defaultdict

# Define a structure to represent an edge in the graph
class Edge:
    def __init__(self, to, pre, c):
        self.to = to
        self.pre = pre
        self.c = c

# Define some variables and arrays for storing information about the graph
N = 10**5 + 10
e = [None] * (N << 1)
u = [0] * N
l = 0
vis = [False] * N
cnt = [0] * 3
d = [0] * N
T = 0
ok = True

def ins(a, b, c):
    global l
    l += 1
    e[l] = Edge(b, u[a], c)
    u[a] = l

# Define a function to perform a depth-first search of the graph
def dfs(x, l):
    global T, ok
    vis[x] = True
    cnt[l] += 1
    d[x] = l
    i = u[x]
    while i:
        v = e[i].to
        ec = e[i].c
        T += 1
        if not vis[v]:
            dfs(v, (l + ec) % 3)
        elif (l + ec) % 3 != d[v]:
            ok = False
        i = e[i].pre

# Define the main function to read the input and compute the answer
def main():
    global T, ok
    n, m = map(int, sys.stdin.readline().split())
    ans = 0
    for i in range(1, n + 1):
        if not vis[i]:
            T = 0
            for j in range(3):
                cnt[j] = 0
            ok = True
            # Perform a depth-first search for the current unvisited node
            dfs(i, 0)
            s = cnt[0] + cnt[1] + cnt[2]
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

if __name__ == "__main__":
    main()

# <END-OF-CODE>
