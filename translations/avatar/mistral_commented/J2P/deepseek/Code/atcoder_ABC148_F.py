from collections import defaultdict, deque
import sys

def main():
    # Read the number of nodes N from the standard input
    N = int(input().strip())
    # Read the indices u and v of the two nodes from the standard input
    u, v = map(int, input().strip().split())
    u -= 1
    v -= 1

    # Initialize the adjacency lists for the graph
    edges = defaultdict(list)
    # Read the edges of the graph from the standard input and add them to the adjacency lists
    for _ in range(N - 1):
        a, b = map(int, input().strip().split())
        a -= 1
        b -= 1
        # Add the edge between nodes a and b to both adjacency lists
        edges[a].append(b)
        edges[b].append(a)

    # Initialize the distance arrays d and e for depth-first search
    d = [sys.maxsize] * N
    e = [sys.maxsize] * N

    # Perform depth-first search from nodes u and v and store the distances in arrays d and e, respectively
    dfs(u, d, edges)
    dfs(v, e, edges)

    # Find the maximum difference between the distances of any node from u and v
    q = -1
    for i in range(N):
        if d[i] < e[i]:
            if e[i] > q:
                q = e[i]

    # Print the result: the maximum difference between the distances of any node from u and v
    if q <= 0:
        print(0)
    else:
        print(q - 1)

def dfs(u, d, edges):
    for nu in edges[u]:
        if d[nu] == sys.maxsize:
            # Mark the current node as visited and update the distance of its neighbors
            d[nu] = d[u] + 1
            dfs(nu, d, edges)

if __name__ == "__main__":
    main()
