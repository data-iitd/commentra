

import sys

def main():
    # Read the number of nodes N from the standard input
    N = int(input())
    # Read the indices u and v of the two nodes from the standard input
    u = int(input()) - 1
    v = int(input()) - 1

    # Initialize the adjacency lists for the graph
    edges = [[] for _ in range(N)]
    # Read the edges of the graph from the standard input and add them to the adjacency lists
    for _ in range(N - 1):
        a, b = map(int, input().split())
        # Add the edge between nodes a and b to both adjacency lists
        edges[a - 1].append(b - 1)
        edges[b - 1].append(a - 1)

    # Initialize the distance arrays d and e for depth-first search
    d = [float('inf')] * N
    e = [float('inf')] * N
    # Perform depth-first search from nodes u and v and store the distances in arrays d and e, respectively
    dfs(u, d, edges)
    dfs(v, e, edges)

    # Find the maximum difference between the distances of any node from u and v
    q = -1
    for i in range(N):
        if d[i] < e[i]:
            q = max(q, e[i])

    # Print the result: the maximum difference between the distances of any node from u and v
    if q <= 0:
        print(0)
    else:
        print(q - 1)

# Depth-first search recursive helper method
def dfs(u, d, edges):
    for nu in edges[u]:
        if d[nu] == float('inf'):
            # Mark the current node as visited and update the distance of its neighbors
            d[nu] = d[u] + 1
            dfs(nu, d, edges)

if __name__ == "__main__":
    main()

