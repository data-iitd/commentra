

import sys
sys.setrecursionlimit(10**6)

def dfs(u, d, edges):
    for nu in edges[u]:
        if d[nu] == float('inf'):
            d[nu] = d[u] + 1
            dfs(nu, d, edges)

def main():
    # Step 1: Read the input values for N, u, and v
    N, u, v = map(int, input().split())
    u -= 1
    v -= 1

    # Step 2: Initialize the adjacency list for the graph
    edges = [[] for _ in range(N)]

    # Step 3: Read the edges of the graph and populate the adjacency list
    for _ in range(N - 1):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        edges[a].append(b)
        edges[b].append(a)

    # Step 4: Initialize the distance array for the first DFS traversal starting from node u
    d = [float('inf')] * N
    d[u] = 0

    # Step 5: Perform DFS from node u to populate the distance array d
    dfs(u, d, edges)

    # Step 6: Initialize the distance array for the second DFS traversal starting from node v
    e = [float('inf')] * N
    e[v] = 0

    # Step 7: Perform DFS from node v to populate the distance array e
    dfs(v, e, edges)

    # Step 8: Find the maximum value of e[i] where d[i] < e[i]
    q = -1
    for i in range(N):
        if d[i] < e[i]:
            q = max(q, e[i])

    # Step 9: Print the result based on the maximum value found
    if q <= 0:
        print(0)
    else:
        print(q - 1)

if __name__ == '__main__':
    main()

