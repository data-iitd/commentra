from collections import defaultdict, deque

# Class representing a binary tree
class BinaryTree:
    # Inner class representing a node in the binary tree
    class Node:
        def __init__(self, data):
            self.data = data  # Value of the node
            self.left = None  # Pointer to left child
            self.right = None  # Pointer to right child

def vertical_traversal(root):
    # If the root is None, return an empty list
    if root is None:
        return []

    # Queues to hold nodes and their corresponding vertical indices
    queue = deque()
    index = deque()
    
    # Map to hold lists of node values at each vertical index
    map = defaultdict(list)
    
    # Variables to track the maximum and minimum vertical indices
    max_idx = 0
    min_idx = 0

    # Start with the root node at index 0
    queue.append(root)
    index.append(0)

    # Perform a level-order traversal of the tree
    while queue:
        node = queue.popleft()  # Get the current node
        idx = index.popleft()  # Get the corresponding index

        # Add the node's value to the list for the current index
        map[idx].append(node.data)

        # Update the maximum and minimum indices
        max_idx = max(max_idx, idx)
        min_idx = min(min_idx, idx)

        # Add left child to the queue with index decremented by 1
        if node.left is not None:
            queue.append(node.left)
            index.append(idx - 1)
        # Add right child to the queue with index incremented by 1
        if node.right is not None:
            queue.append(node.right)
            index.append(idx + 1)

    # Prepare the result list for vertical traversal output
    result = []
    # Collect values from the map in order of vertical indices
    for i in range(min_idx, max_idx + 1):
        result.extend(map[i])
    
    return result  # Return the final result list

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    # Read the number of nodes in the binary tree
    n = int(data[0])
    
    # Array to hold references to the nodes
    nodes = [None] * (n + 1)
    
    # Initialize nodes with their respective values
    for i in range(1, n + 1):
        nodes[i] = BinaryTree.Node(i)
    
    # Read the edges and construct the binary tree
    for i in range(1, n):
        parent, child, direction = data[i].split()
        parent = int(parent)
        child = int(child)

        # Link the child to the parent based on the direction
        if direction == "L":
            nodes[parent].left = nodes[child]  # Set left child
        elif direction == "R":
            nodes[parent].right = nodes[child]  # Set right child

    # Perform vertical traversal starting from the root node
    result = vertical_traversal(nodes[1])
    
    # Print the result of the vertical traversal
    print(" ".join(map(str, result)))

# <END-OF-CODE>
