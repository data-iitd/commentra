class Node:
    # Constants representing the colors of the nodes
    RED = 0
    BLACK = 1

    def __init__(self, key):
        self.key = key  # The key value of the node
        self.color = Node.BLACK  # The color of the node, default is BLACK
        self.left = None  # Pointer to left child
        self.right = None  # Pointer to right child
        self.p = None  # Pointer to parent


class RedBlackTree:
    def __init__(self):
        self.nil = Node(-1)  # Sentinel node representing the nil node (leaf node)
        self.root = self.nil  # The root of the Red-Black Tree

    def print_tree(self, node):
        if node == self.nil:
            return  # Base case: if the node is nil, return
        self.print_tree(node.left)  # Recursively print the left subtree
        # Print the current node with its color
        print(f"{'R' if node.color == Node.RED else 'B'} {node.key}", end=" ")
        self.print_tree(node.right)  # Recursively print the right subtree

    def insert(self, key):
        node = Node(key)  # Create a new node for the key
        temp = self.root  # Start from the root

        # If the tree is empty, set the new node as the root and color it black
        if self.root == self.nil:
            self.root = node
            node.color = Node.BLACK
        else:
            node.color = Node.RED  # New nodes are always red
            while True:
                # Traverse the tree to find the correct position for the new node
                if key < temp.key:
                    if temp.left is None:
                        temp.left = node  # Insert as left child
                        node.p = temp  # Set parent
                        break
                    temp = temp.left  # Move to left child
                else:
                    if temp.right is None:
                        temp.right = node  # Insert as right child
                        node.p = temp  # Set parent
                        break
                    temp = temp.right  # Move to right child
            # Fix the tree to maintain Red-Black properties
            self.fix_tree(node)

    def fix_tree(self, node):
        while node.p and node.p.color == Node.RED:  # While the parent is red
            if node.p == node.p.p.left:  # If the parent is a left child
                y = node.p.p.right  # Uncle node
                if y and y.color == Node.RED:  # Case 1: Uncle is red
                    # Recoloring
                    node.p.color = Node.BLACK
                    y.color = Node.BLACK
                    node.p.p.color = Node.RED
                    node = node.p.p  # Move up the tree
                else:
                    # Case 2: Node is a right child
                    if node == node.p.right:
                        node = node.p  # Move node up
                        self.rotate_left(node)  # Perform left rotation
                    # Case 3: Node is a left child
                    node.p.color = Node.BLACK
                    node.p.p.color = Node.RED
                    self.rotate_right(node.p.p)  # Perform right rotation
            else:  # If the parent is a right child
                y = node.p.p.left  # Uncle node
                if y and y.color == Node.RED:  # Case 1: Uncle is red
                    # Recoloring
                    node.p.color = Node.BLACK
                    y.color = Node.BLACK
                    node.p.p.color = Node.RED
                    node = node.p.p  # Move up the tree
                else:
                    # Case 2: Node is a left child
                    if node == node.p.left:
                        node = node.p  # Move node up
                        self.rotate_right(node)  # Perform right rotation
                    # Case 3: Node is a right child
                    node.p.color = Node.BLACK
                    node.p.p.color = Node.RED
                    self.rotate_left(node.p.p)  # Perform left rotation
        self.root.color = Node.BLACK  # Ensure the root is always black

    def rotate_left(self, node):
        temp = node.right  # Store the right child
        node.right = temp.left  # Move the left child of right to the right of the node
        if temp.left:
            temp.left.p = node  # Update parent pointer if not nil
        temp.p = node.p  # Update parent of temp
        if node.p is None:
            self.root = temp  # If node is root, update root
        elif node == node.p.left:
            node.p.left = temp  # Update parent's left child
        else:
            node.p.right = temp  # Update parent's right child
        temp.left = node  # Make node the left child of temp
        node.p = temp  # Update parent pointer of node

    def rotate_right(self, node):
        temp = node.left  # Store the left child
        node.left = temp.right  # Move the right child of left to the left of the node
        if temp.right:
            temp.right.p = node  # Update parent pointer if not nil
        temp.p = node.p  # Update parent of temp
        if node.p is None:
            self.root = temp  # If node is root, update root
        elif node == node.p.right:
            node.p.right = temp  # Update parent's right child
        else:
            node.p.left = temp  # Update parent's left child
        temp.right = node  # Make node the right child of temp
        node.p = temp  # Update parent pointer of node

    def print_in_order(self):
        self.print_tree(self.root)  # Call the print_tree method starting from the root
        print()  # Print a new line after traversal


# Main method to execute the program
if __name__ == "__main__":
    n = int(input("Enter the number of keys to insert: "))  # Read the number of keys to insert
    rb_tree = RedBlackTree()  # Create an instance of the Red-Black Tree
    for _ in range(n):
        key = int(input())  # Read each key
        rb_tree.insert(key)  # Insert the key into the tree
    print("In-order traversal:")  # Print message before traversal
    rb_tree.print_in_order()  # Print the tree in-order

# <END-OF-CODE>
