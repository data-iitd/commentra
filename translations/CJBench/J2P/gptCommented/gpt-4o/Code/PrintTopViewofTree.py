from collections import deque

# Class representing a node in the binary tree
class TreeNode:
    def __init__(self, key):
        self.key = key  # Value of the node
        self.left = None  # Left child of the node
        self.right = None  # Right child of the node

# Class representing an item in the queue for level order traversal
class QItem:
    def __init__(self, node, hd):
        self.node = node  # The tree node
        self.hd = hd  # Horizontal distance from the root

# Class representing the binary tree
class Tree:
    def __init__(self, root):
        self.root = root  # Root node of the tree

    # Method to print the top view of the binary tree
    def print_top_view(self):
        if self.root is None:
            return

        # Set to keep track of horizontal distances that have been printed
        printed_hd = set()
        # Queue for level order traversal
        queue = deque()
        # Start with the root node at horizontal distance 0
        queue.append(QItem(self.root, 0))

        # Process nodes in the queue until it's empty
        while queue:
            qi = queue.popleft()  # Get the front item from the queue
            hd = qi.hd  # Get the horizontal distance
            node = qi.node  # Get the tree node

            # If this horizontal distance has not been printed yet, print the node's key
            if hd not in printed_hd:
                printed_hd.add(hd)  # Mark this horizontal distance as printed
                print(node.key, end=" ")  # Print the node's key

            # If there is a left child, add it to the queue with horizontal distance -1
            if node.left is not None:
                queue.append(QItem(node.left, hd - 1))
            # If there is a right child, add it to the queue with horizontal distance +1
            if node.right is not None:
                queue.append(QItem(node.right, hd + 1))

# Main function to execute the program
def main():
    n = int(input())  # Read the number of nodes

    # Dictionary to store nodes by their keys
    node_map = {}

    # Read each node's key and its children
    for _ in range(n):
        key, left, right = map(int, input().split())  # Read the node key and its children

        # Create the current node if it does not exist in the map
        if key not in node_map:
            node_map[key] = TreeNode(key)
        current_node = node_map[key]  # Get the current node

        # If there is a left child, create it and link it to the current node
        if left != -1:
            if left not in node_map:
                node_map[left] = TreeNode(left)
            current_node.left = node_map[left]
        # If there is a right child, create it and link it to the current node
        if right != -1:
            if right not in node_map:
                node_map[right] = TreeNode(right)
            current_node.right = node_map[right]

    # Read the key of the root node
    root_key = int(input())
    # Create the tree with the specified root
    tree = Tree(node_map[root_key])

    # Print the top view of the binary tree
    print("Top view of the binary tree:")
    tree.print_top_view()  # Call the method to print the top view

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
