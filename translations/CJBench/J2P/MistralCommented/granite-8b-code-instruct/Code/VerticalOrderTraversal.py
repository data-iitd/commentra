
import sys
from collections import deque

class BinaryTree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

# Function to perform vertical traversal of a binary tree
def verticalTraversal(root):
    # Base case: if root is None, return an empty list
    if root is None:
        return []

    # Initialize queues for nodes and their corresponding indices
    queue = deque()
    index = deque()

    # Initialize a map to store the data at each index
    map = {}

    # Initialize minimum and maximum indices
    max_idx = 0
    min_idx = 0

    # Enqueue the root node and its index in the queues
    queue.append(root)
    index.append(0)

    # BFS traversal using queues
    while queue:
        # Dequeue a node and its corresponding index
        node = queue.popleft()
        idx = index.popleft()

        # Add the node's data to the map at the corresponding index
        if idx not in map:
            map[idx] = []
        map[idx].append(node.data)

        # Update the minimum and maximum indices
        max_idx = max(max_idx, idx)
        min_idx = min(min_idx, idx)

        # Enqueue the left and right children and their indices
        if node.left is not None:
            queue.append(node.left)
            index.append(idx - 1)
        if node.right is not None:
            queue.append(node.right)
            index.append(idx + 1)

    # Create an empty result list
    result = []

    # Add all the data from the map to the result list
    for i in range(min_idx, max_idx + 1):
        result.extend(map[i])

    # Return the result list
    return result

# Main method to read input and call the verticalTraversal function
def main():
    # Read the number of nodes in the binary tree
    n = int(input())

    # Create an array of nodes for the binary tree
    nodes = [BinaryTree.Node(i) for i in range(1, n + 1)]

    # Read the edges and their directions from the input
    for _ in range(n - 1):
        parent, child, direction = map(str, input().split())
        parent = int(parent)
        child = int(child)

        # Connect the parent and child nodes based on the direction
        if direction == "L":
            nodes[parent - 1].left = nodes[child - 1]
        else:
            nodes[parent - 1].right = nodes[child - 1]

    # Call the verticalTraversal function on the root node and print the result
    result = verticalTraversal(nodes[0])
    print(" ".join(map(str, result)))

if __name__ == "__main__":
    sys.exit(main())

