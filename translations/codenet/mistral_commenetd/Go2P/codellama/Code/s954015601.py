// 深さ優先探索
import sys

# Function to generate unique id based on two integers
def genid(a, b):
    if b < a:
        a, b = b, a
    # Multiply the larger number by 100000 and add the smaller number
    return a*100000 + b

# Main function
def main():
    # Read the number of edges in the graph
    N = int(sys.stdin.readline())

    # Initialize an adjacency list and a 2D array to store the edges between nodes
    ab = [[0, 0] for _ in range(N-1)]
    edges = [[] for _ in range(N)]
    for i in range(N-1):
        # Read two integers representing the nodes connected by an edge
        a, b = map(int, sys.stdin.readline().split())
        # Store the nodes and their indices in the ab array
        ab[i][0], ab[i][1] = a-1, b-1
        # Add the edge to the adjacency list
        edges[a-1].append(b-1)
        edges[b-1].append(a-1)

    # Initialize a map to store the colors of each connected component
    colors = {}
    # Initialize a queue to perform DFS
    q = []
    # Add the first node to the queue with initial color and parent node set to -1
    q.append([0, -1, -1])
    while len(q) != 0:
        # Dequeue the current node, its color, and its parent node
        currentNode, usedColor, parentNode = q.pop()
        # Set the color of the current node to the next available color
        color = 1
        for childNode in edges[currentNode]:
            if childNode == parentNode:
                continue
            # If the color of the current node is the same as the color of the child node, increment the color
            if color == usedColor:
                color += 1
            # Assign the color to the child node and add it to the queue with the current node as its parent node
            colors[genid(currentNode, childNode)] = color
            q.append([childNode, color, currentNode])
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
    for i in range(N-1):
        print(colors[genid(ab[i][0], ab[i][1])])

# 