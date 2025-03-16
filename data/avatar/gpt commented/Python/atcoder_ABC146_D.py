from collections import deque
import sys

# Use fast input method
input = sys.stdin.readline

def bfs(v, N, G, E):
    # Initialize visited list to keep track of visited nodes
    visited = [0] * N
    # Initialize a queue for BFS
    queue = deque()
    K = -1  # Variable to track the maximum color used
    # Initialize a list to store the color assigned to each node
    node2color = [-1 for _ in range(N)]
    
    # Start BFS from the given vertex 'v'
    queue.append(v)
    visited[v] = 1  # Mark the starting node as visited
    
    while queue:
        # Dequeue the front node
        q = queue.popleft()
        color = 0  # Initialize color counter for the current node
        
        # Explore all adjacent nodes
        for nex in G[q]:
            if visited[nex]:
                continue  # Skip if the node has already been visited
            
            visited[nex] = 1  # Mark the adjacent node as visited
            color += 1  # Increment the color counter
            
            # Ensure the color assigned to the next node is different from the current node's color
            if color == node2color[q]:
                color += 1
            
            # Assign the color to the adjacent node
            node2color[nex] = color
            
            # Store the color used for the edge between the current node and the adjacent node
            E[(min(q, nex), max(q, nex))] = color
            
            # Enqueue the adjacent node for further exploration
            queue.append(nex)
        
        # Update the maximum color used
        K = max(K, color)
    
    return K  # Return the maximum color used

def main():
    # Read the number of nodes
    N = int(input())
    # Initialize the graph as a list of deques
    G = [deque() for _ in range(N)]
    # Initialize a dictionary to store edge colors
    E = dict()
    
    # Read edges and build the graph
    for i in range(N - 1):
        a, b = map(lambda x: int(x) - 1, input().split())
        G[a].append(b)  # Add edge from a to b
        G[b].append(a)  # Add edge from b to a
        E[(a, b)] = 0  # Initialize edge color to 0
    
    # Perform BFS starting from node 0
    K = bfs(0, N, G, E)
    
    # Print the maximum color used
    print(K)
    # Print the colors assigned to each edge
    for value in E.values():
        print(value)

# Entry point of the program
main()
