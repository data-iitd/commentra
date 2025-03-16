
import queue

# Class representing a binary tree
class BinaryTree:
    # Inner class representing a node in the binary tree
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

def verticalTraversal(root):
    # If the root is None, return an empty list
    if root is None:
        return []

    # Queues to hold nodes and their corresponding vertical indices
    node_queue = queue.Queue()
    index_queue = queue.Queue()
    
    # Map to hold lists of node values at each vertical index
    map = {}
    
    # Variables to track the maximum and minimum vertical indices
    max_index = 0
    min_index = 0

    # Start with the root node at index 0
    node_queue.put(root)
    index_queue.put(0)

    # Perform a level-order traversal of the tree
    while not node_queue.empty():
        node = node_queue.get() # Get the current node
        index = index_queue.get() # Get the corresponding index

        # Add the node's value to the list for the current index
        map[index] = map.get(index, []) + [node.data]

        # Update the maximum and minimum indices
        max_index = max(max_index, index)
        min_index = min(min_index, index)

        # Add left child to the queue with index decremented by 1
        if node.left is not None:
            node_queue.put(node.left)
            index_queue.put(index - 1)
        # Add right child to the queue with index incremented by 1
        if node.right is not None:
            node_queue.put(node.right)
            index_queue.put(index + 1)

    # Prepare the result list for vertical traversal output
    result = []
    # Collect values from the map in order of vertical indices
    for i in range(min_index, max_index + 1):
        result.extend(map.get(i, []))
    return result # Return the final result list

if __name__ == "__main__":
    # Create a scanner to read input
    scanner = input()
    
    # Read the number of nodes in the binary tree
    n = int(scanner.readline())
    
    # Array to hold references to the nodes
    nodes = [None] * (n + 1)
    
    # Initialize nodes with their respective values
    for i in range(1, n + 1):
        nodes[i] = BinaryTree.Node(i)
    
    # Read the edges and construct the binary tree
    for i in range(n - 1):
        parent, child, direction = scanner.readline().split()
        parent = int(parent)
        child = int(child)
        
        # Link the child to the parent based on the direction
        if direction == "L":
            nodes[parent].left = nodes[child] # Set left child
        else:
            nodes[parent].right = nodes[child] # Set right child
    
    # Perform vertical traversal starting from the root node
    result = verticalTraversal(nodes[1])
    
    # Print the result of the vertical traversal
    print(" ".join(map(str, result)))
    
    # Close the scanner
    scanner.close()

