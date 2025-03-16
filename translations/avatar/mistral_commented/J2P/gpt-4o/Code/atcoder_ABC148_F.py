from collections import defaultdict

def dfs(u, d, edges):
    for nu in edges[u]:
        if d[nu] == float('inf'):
            # Mark the current node as visited and update the distance of its neighbors
            d[nu] = d[u] + 1
            dfs(nu, d, edges)

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    # Read the number of nodes N from the standard input
    N = int(data[index])
    index += 1
    # Read the indices u and v of the two nodes from the standard input
    u = int(data[index]) - 1
    index += 1
    v = int(data[index]) - 1
    index += 1

    # Initialize the adjacency lists for the graph
    edges = defaultdict(list)

    # Read the edges of the graph from the standard input and add them to the adjacency lists
    for _ in range(N - 1):
        a = int(data[index]) - 1
        index += 1
        b = int(data[index]) - 1
        index += 1
        # Add the edge between nodes a and b to both adjacency lists
        edges[a].append(b)
        edges[b].append(a)

    # Initialize the distance arrays d and e for depth-first search
    d = [float('inf')] * N
    e = [float('inf')] * N

    # Perform depth-first search from nodes u and v and store the distances in arrays d and e, respectively
    d[u] = 0
    dfs(u, d, edges)
    
    e[v] = 0
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

if __name__ == "__main__":
    main()

# <END-OF-CODE>
