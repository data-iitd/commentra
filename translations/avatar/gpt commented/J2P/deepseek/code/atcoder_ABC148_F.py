import sys
from collections import defaultdict, deque

def main():
    # Read the number of nodes (N) and the two specific nodes (u and v)
    N = int(input().strip())
    u, v = map(int, input().strip().split())
    u -= 1  # Convert to zero-based index
    v -= 1  # Convert to zero-based index
    
    # Create an adjacency list to represent the edges of the graph
    edges = defaultdict(list)
    
    # Read the edges and populate the adjacency list
    for _ in range(N - 1):
        a, b = map(int, input().strip().split())
        a -= 1  # Convert to zero-based index
        b -= 1  # Convert to zero-based index
        edges[a].append(b)  # Add edge from a to b
        edges[b].append(a)  # Add edge from b to a (undirected graph)
    
    # Initialize distance array for the first node (u)
    d = [sys.maxsize] * N
    d[u] = 0  # Distance to itself is 0
    
    # Perform BFS from node u to calculate distances
    queue = deque([u])
    while queue:
        node = queue.popleft()
        for neighbor in edges[node]:
            if d[neighbor] == sys.maxsize:  # If the node has not been visited
                d[neighbor] = d[node] + 1  # Update the distance
                queue.append(neighbor)  # Add the neighbor to the queue
    
    # Initialize distance array for the second node (v)
    e = [sys.maxsize] * N
    e[v] = 0  # Distance to itself is 0
    
    # Perform BFS from node v to calculate distances
    queue = deque([v])
    while queue:
        node = queue.popleft()
        for neighbor in edges[node]:
            if e[neighbor] == sys.maxsize:  # If the node has not been visited
                e[neighbor] = e[node] + 1  # Update the distance
                queue.append(neighbor)  # Add the neighbor to the queue
    
    # Find the maximum distance from node u to any node that is closer to v
    q = -1
    for i in range(N):
        if d[i] < e[i]:  # Check if node i is closer to u than to v
            if e[i] > q:  # Update q if the distance to v is greater
                q = e[i]
    
    # Output the result based on the maximum distance found
    if q <= 0:
        print(0)  # If no valid distance found, print 0
    else:
        print(q - 1)  # Print the maximum distance minus 1

if __name__ == "__main__":
    main()
