import sys

# Set the maximum recursion limit to handle deep recursions
sys.setrecursionlimit(10 ** 5)

# Define a class to represent each node in the graph
class Node:
    def __init__(self):
        self.val = None  # Value of the node
        self.color = None  # Color of the node (True/False)
        self.a = []  # Adjacency list to store connected nodes and weights

# Read the number of nodes from input
n = int(input())
nodes = []

# Initialize nodes and store them in a list
for i in range(n):
    nodes.append(Node())

# Read edges and construct the graph
for i in range(n - 1):
    u, v, w = map(int, input().split())
    node1 = nodes[u - 1]  # Get the first node (adjusting for 0-indexing)
    node2 = nodes[v - 1]  # Get the second node (adjusting for 0-indexing)
    node1.val = u  # Set the value of the first node
    node2.val = v  # Set the value of the second node
    # Add the edge to both nodes' adjacency lists
    node1.a.append([node2, w])
    node2.a.append([node1, w])

# Set the root node and initialize its color
root = nodes[0]
root.color = True  # Color the root node as True
nodeSet = set()  # Set to keep track of visited nodes

# Define a recursive function to traverse the graph
def traverse(node, distance):
    # If the node has already been visited, return
    if node in nodeSet:
        return
    else:
        nodeSet.add(node)  # Mark the node as visited

    # Iterate through each adjacent node
    for pair in node.a:
        adjNode = pair[0]  # Get the adjacent node
        dis = pair[1]  # Get the distance (weight) to the adjacent node
        # Determine the color of the adjacent node based on the distance
        if (distance + dis) % 2 == 0:
            adjNode.color = root.color  # Same color as root
        else:
            adjNode.color = not root.color  # Opposite color to root
        # Recursively traverse to the adjacent node
        traverse(adjNode, distance + dis)

# Start the traversal from the root node with an initial distance of 0
traverse(root, 0)

# Output the color of each node
for i in range(n):
    node = nodes[i]
    if node.color:
        print(1)  # Print 1 for True color
    else:
        print(0)  # Print 0 for False color
