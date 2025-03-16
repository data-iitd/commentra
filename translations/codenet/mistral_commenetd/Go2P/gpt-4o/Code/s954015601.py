# 深さ優先探索
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
    N = read_int()

    # Initialize an adjacency list and a list to store the edges between nodes
    ab = []
    edges = defaultdict(list)
    for _ in range(N - 1):
        # Read two integers representing the nodes connected by an edge
        a = read_int() - 1
        b = read_int() - 1
        # Store the nodes in the ab list
        ab.append((a, b))
        # Add the edge to the adjacency list
        edges[a].append(b)
        edges[b].append(a)

    # Initialize a dictionary to store the colors of each connected component
    colors = {}
    # Initialize a stack to perform DFS
    stack = [(0, -1, -1)]  # (currentNode, usedColor, parentNode)
    while stack:
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
    K = -1
    # Iterate through all nodes in the graph and update the maximum number of edges if necessary
    for i in range(N):
        t = len(edges[i])
        if t > K:
            K = t
    # Print the maximum number of edges in a connected component
    print(K)

    # Iterate through all edges in the graph and print their colors
    for a, b in ab:
        print(colors[genid(a, b)])

# Function to read a single integer from standard input
def read_int():
    return int(sys.stdin.readline().strip())

if __name__ == "__main__":
    main()

# <END-OF-CODE>
