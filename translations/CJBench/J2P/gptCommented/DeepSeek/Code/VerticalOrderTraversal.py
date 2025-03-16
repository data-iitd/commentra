from collections import defaultdict, deque

# Class representing a binary tree
class BinaryTree:
    # Inner class representing a node in the binary tree
    class Node:
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
    queue = deque()
    index_queue = deque()
    
    # Map to hold lists of node values at each vertical index
    map = defaultdict(list)
    
    # Variables to track the maximum and minimum vertical indices
    max_index = 0
    min_index = 0

    # Start with the root node at index 0
    queue.append(root)
    index_queue.append(0)

    # Perform a level-order traversal of the tree
    while queue:
        node = queue.popleft() # Get the current node
        idx = index_queue.popleft() # Get the corresponding index

        # Add the node's value to the list for the current index
        map[idx].append(node.data)

        # Update the maximum and minimum indices
        max_index = max(max_index, idx)
        min_index = min(min_index, idx)

        # Add left child to the queue with index decremented by 1
        if node.left:
            queue.append(node.left)
            index_queue.append(idx - 1)

        # Add right child to the queue with index incremented by 1
        if node.right:
            queue.append(node.right)
            index_queue.append(idx + 1)

    # Prepare the result list for vertical traversal output
    result = []
    # Collect values from the map in order of vertical indices
    for i in range(min_index, max_index + 1):
        result.extend(map[i])
    return result # Return the final result list

# Main function to read input and perform vertical traversal
def main():
    # Create a scanner to read input
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Read the number of nodes in the binary tree
    n = int(data[0])
    
    # Array to hold references to the nodes
    nodes = [BinaryTree.Node(i) for i in range(n + 1)]
    
    # Read the edges and construct the binary tree
    index = 1
    for i in range(1, n):
        parent = int(data[index])
        child = int(data[index + 1])
        direction = data[index + 2]
        index += 3

        # Link the child to the parent based on the direction
        if direction == "L":
            nodes[parent].left = nodes[child] # Set left child
        elif direction == "R":
            nodes[parent].right = nodes[child] # Set right child

    # Perform vertical traversal starting from the root node
    result = verticalTraversal(nodes[1])
    
    # Print the result of the vertical traversal
    print(" ".join(map(str, result)))

# Call the main function
if __name__ == "__main__":
    main()
