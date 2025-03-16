#######
# Code
#######

# Import necessary libraries
from collections import deque
import sys

# Function to perform Breadth First Search (BFS)
def bfs(v, N, G, E):
    # Initialize visited array and queue
    visited = [0] * N
    queue = deque()

    # Initialize variables for coloring nodes
    K = -1
    node2color = [ -1 for _ in range(N) ]

    # Add starting node to the queue and mark it as visited
    queue.append(v)
    visited[v] = 1

    # BFS algorithm
    while queue:
        # Dequeue the next node from the queue
        q = queue.popleft()

        # Initialize color for the current node
        color = 0

        # Traverse through all neighbors of the current node
        for nex in G[q]:
            # Skip if the neighbor is already visited
            if visited[nex]:
                continue

            # Mark the neighbor as visited and assign it a color
            visited[nex] = 1
            color += 1

            # If the color of the current node is same as its neighbor, assign a new color to the neighbor
            if color == node2color[q]:
                color += 1

            # Update node2color and E dictionary with the new color
            node2color[nex] = color
            E[(min(q, nex), max(q, nex))] = color

            # Add the neighbor to the queue
            queue.append(nex)

        # Update the maximum color found so far
        K = max(K, color)

    # Return the maximum color
    return K

# Main function to read input and call bfs function
def main():
    # Read number of nodes from the input
    N = int(input())

    # Initialize graph as a list of deques and empty dictionary for edges
    G = [deque() for _ in range(N)]
    E = {}

    # Read edges from the input and add them to the graph
    for i in range(N-1):
        a, b = map(lambda x: int(x)-1, input().split())
        G[a].append(b)
        G[b].append(a)
        E[(a, b)] = 0

    # Call bfs function and print the result
    K = bfs(0, N, G, E)
    print(K)

    # Print colors of all edges
    for value in E.values():
        print(value)

# Call the main function
main()
