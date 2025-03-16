
# Import modules
import sys

# Class representing a binary tree
class BinaryTree:
    # Inner class representing a node in the binary tree
    class Node:
        # Constructor to initialize the node with data
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

# Method to perform vertical traversal of the binary tree
def verticalTraversal(root):
    # If the root is None, return an empty list
    if root is None:
        return []

    # Queues to hold nodes and their corresponding vertical indices
    queue = []
    index = []

    # Map to hold lists of node values at each vertical index
    map = {}

    # Variables to track the maximum and minimum vertical indices
    max = 0
    min = 0

    # Start with the root node at index 0
    queue.append(root)
    index.append(0)

    # Perform a level-order traversal of the tree
    while queue:
        node = queue.pop(0) # Get the current node
        idx = index.pop(0) # Get the corresponding index

        # Add the node's value to the list for the current index
        map[idx] = map.get(idx, []) + [node.data]

        # Update the maximum and minimum indices
        max = max(max, idx)
        min = min(min, idx)

        # Add left child to the queue with index decremented by 1
        if node.left:
            queue.append(node.left)
            index.append(idx - 1)

        # Add right child to the queue with index incremented by 1
        if node.right:
            queue.append(node.right)
            index.append(idx + 1)

    # Prepare the result list for vertical traversal output
    result = []
    # Collect values from the map in order of vertical indices
    for i in range(min, max + 1):
        result.extend(map.get(i, []))
    return result # Return the final result list

# Main function
if __name__ == "__main__":
    # Read the number of nodes in the binary tree
    n = int(sys.stdin.readline().strip())

    # Array to hold references to the nodes
    nodes = [None] * (n + 1)

    # Initialize nodes with their respective values
    for i in range(1, n + 1):
        nodes[i] = BinaryTree.Node(i)

    # Read the edges and construct the binary tree
    for i in range(n - 1):
        parent, child = map(int, sys.stdin.readline().strip().split())
        direction = sys.stdin.readline().strip()

        # Link the child to the parent based on the direction
        if direction == "L":
            nodes[parent].left = nodes[child] # Set left child
        else:
            nodes[parent].right = nodes[child] # Set right child

    # Perform vertical traversal starting from the root node
    result = verticalTraversal(nodes[1])

    # Print the result of the vertical traversal
    print(" ".join(map(str, result)))

