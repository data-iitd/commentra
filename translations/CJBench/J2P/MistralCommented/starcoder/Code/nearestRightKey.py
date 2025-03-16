
import sys

# Initialize a map to store nodes in the tree
nodeMap = {}

# Initialize root node to null
root = None

# Read the number of nodes in the tree
n = int(sys.stdin.readline())

# Read each node and create a new node if it doesn't exist in the map
# Put the node in the map and set its left and right children if they exist
for i in range(n):
    value, left, right = map(int, sys.stdin.readline().split())

    # Create a new node if it doesn't exist in the map
    if value not in nodeMap:
        nodeMap[value] = NRKTree(value)

    # Get the current node
    current = nodeMap[value]

    # If root is null, set the current node as the root
    if root is None:
        root = current

    # Set the left child of the current node if it exists
    if left!= -1:
        if left not in nodeMap:
            nodeMap[left] = NRKTree(left)
        current.left = nodeMap[left]

    # Set the right child of the current node if it exists
    if right!= -1:
        if right not in nodeMap:
            nodeMap[right] = NRKTree(right)
        current.right = nodeMap[right]

# Read the input value x0
inputX0 = int(sys.stdin.readline())

# Call the recursive function to find the nearest right key
toPrint = Main(root, inputX0)

# Print the result
if toPrint == 0:
    print("No nearest right key found.")
else:
    print("Nearest Right Key: " + str(toPrint))

# 