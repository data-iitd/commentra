import sys
from collections import defaultdict

# Function to generate unique id based on two integers
def genid(a, b):
    if b < a:
        a, b = b, a
    # Multiply the larger number by 100000 and add the smaller number
    return a * 100000 + b

# Main function
def main():
    # Read the number of edges in the graph
    N = int(sys.stdin.readline().strip())

    # Initialize an adjacency list and a 2D array to store the edges between nodes
    edges = defaultdict(list)
    ab = []
    for _ in range(N - 1):
        # Read two integers representing the nodes connected by an edge
        a, b = map(int, sys.stdin.readline().strip().split())
        # Store the nodes and their indices in the ab array
        ab.append((a - 1, b - 1))
        # Add the edge to the adjacency list
        edges[a - 1].append(b - 1)
        edges[b - 1].append(a - 1)

    # Initialize a map to store the colors of each connected component
    colors = {}
    # Initialize a stack to perform DFS
    stack = [(0, -1, -1)]
    while stack:
        # Pop the current node, its color, and its parent node
        currentNode, usedColor, parentNode = stack.pop()
        # Set the color of the current node to the next available color
        color = 1
        for childNode in edges[currentNode]:
            if childNode == parentNode:
                continue
            # If the color of the current node is the same as the color of the child node, increment the color
            if color == usedColor:
                color += 1
            # Assign the color to the child node and add it to the stack with the current node as its parent node
            colors[genid(currentNode, childNode)] = color
            stack.append((childNode, color, currentNode))
            # Increment the color for the next iteration
            color += 1

    # Initialize a variable to store the maximum number of edges in a connected component
    K = max(len(edges[node]) for node in edges)
    # Print the maximum number of edges in a connected component
    print(K)

    # Iterate through all edges in the graph and print their colors
    for a, b in ab:
        print(colors[genid(a, b)])

# Call the main function
if __name__ == "__main__":
    main()
