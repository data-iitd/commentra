from collections import deque
import sys
input = sys.stdin.readline

# Function to perform Breadth-First Search (BFS) to color the graph
def bfs(v, N, G, E):
    # Initialize visited list to keep track of visited nodes
    visited = [0] * N
    # Initialize a queue for BFS using deque
    queue = deque()
    # Initialize the maximum color index K
    K = -1
    # List to store the color of each node, initialized to -1 (no color)
    node2color = [-1 for _ in range(N)]
    # Start BFS from vertex v
    queue.append(v)
    visited[v] = 1
    while queue:
        # Dequeue the front node
        q = queue.popleft()
        # Initialize color for the current node
        color = 0
        # Iterate over all adjacent nodes
        for nex in G[q]:
            if visited[nex]:
                continue
            visited[nex] = 1
            color += 1
            # Ensure the color is different from the parent node's color
            if color == node2color[q]:
                color += 1
            # Assign the color to the node and record the edge color
            node2color[nex] = color
            E[(min(q, nex), max(q, nex))] = color
            # Enqueue the adjacent node for further exploration
            queue.append(nex)
        # Update the maximum color used
        K = max(K, color)
    return K

# Main function to read input, construct the graph, and execute the BFS
def main():
    # Read the number of nodes N
    N = int(input())
    # Initialize a list of deque objects to represent the graph
    G = [deque() for _ in range(N)]
    # Initialize an empty dictionary to store edge colors
    E = dict()
    # Read edges to populate the graph and edge dictionary
    for i in range(N - 1):
        a, b = map(lambda x: int(x) - 1, input().split())
        G[a].append(b)
        G[b].append(a)
        E[(a, b)] = 0
    # Perform BFS to determine the maximum color and edge colors
    K = bfs(0, N, G, E)
    # Print the maximum color used
    print(K)
    # Print the colors of all edges
    for value in E.values():
        print(value)

# Execute the main function
main()
