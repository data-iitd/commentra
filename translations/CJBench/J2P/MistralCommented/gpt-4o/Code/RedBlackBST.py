class Node:
    # Constants for colors of nodes in the tree
    RED = 0
    BLACK = 1

    def __init__(self, key):
        self.key = key  # Key of the node
        self.color = Node.BLACK  # Color of the node (RED or BLACK)
        self.left = nil  # Left child
        self.right = nil  # Right child
        self.p = nil  # Parent

# Sentinel node representing nil (null)
nil = Node(-1)

class RedBlackTree:
    def __init__(self):
        self.root = nil  # Root of the tree

    def print_tree(self, node):
        # Base case: if node is nil, return
        if node == nil:
            return

        # Recursively print left subtree
        self.print_tree(node.left)

        # Print the node's key and color
        print("R" if node.color == Node.RED else "B", node.key, end=" ")

        # Recursively print right subtree
        self.print_tree(node.right)

    def insert(self, key):
        # Create a new Node with the given key
        node = Node(key)

        temp = self.root

        # Base case: if the tree is empty, make the new node the root
        if self.root == nil:
            self.root = node
            node.color = Node.BLACK
        else:
            # New node is red, so we'll insert it as a leaf
            node.color = Node.RED

            # While we haven't reached the correct position to insert the new node
            while True:
                # If the key is less than the current node's key, go left
                if key < temp.key:
                    if temp.left == nil:
                        # Found the correct position, insert the new node here
                        temp.left = node
                        node.p = temp
                        break
                    temp = temp.left
                else:
                    # If the key is greater than the current node's key, go right
                    if temp.right == nil:
                        # Found the correct position, insert the new node here
                        temp.right = node
                        node.p = temp
                        break
                    temp = temp.right

            # Fix the tree to maintain the red-black tree properties
            self.fix_tree(node)

    def fix_tree(self, node):
        # Base case: if the node's parent is black, we're done
        while node.p.color == Node.RED:
            # Case 1: uncle is red
            y = node.p.p
            if y.color == Node.RED:
                # Make both grandparents black, and make the current node's parent black
                node.p.color = Node.BLACK
                y.color = Node.BLACK

                # Make the current node's grandparent red
                node.p.p.color = Node.RED

                # Recursively fix the tree
                node = node.p.p
            else:
                # Case 2: uncle is black, so we'll perform a rotation to rebalance the tree
                if node == node.p.left:
                    # Perform a left rotation
                    node = node.p
                    self.rotate_left(node)

                # Perform a right rotation on the node's parent
                node.p.color = Node.BLACK
                node.p.p.color = Node.RED
                self.rotate_right(node.p.p)

        # Make the root black
        self.root.color = Node.BLACK

    def rotate_left(self, node):
        # Save the right child
        temp = node.right

        # Set the right child of the node to the left child of the right child
        node.right = temp.left

        # If the left child of the right child is not nil, set its parent to the node
        if temp.left != nil:
            temp.left.p = node

        # Set the left child of the right child as the new node's left child
        temp.left = node

        # Set the parent of the right child to the node's parent
        temp.p = node.p

        # If the node's parent is nil, make the new right child the root
        if node.p == nil:
            self.root = temp
        elif node == node.p.left:
            node.p.left = temp
        else:
            node.p.right = temp

        # Set the new right child as the node's left child
        node.left = temp

        # Set the node as the new right child of the right child
        temp.p = node

    def rotate_right(self, node):
        # Save the left child
        temp = node.left

        # Set the left child of the node to the right child of the left child
        node.left = temp.right

        # If the right child of the left child is not nil, set its parent to the node
        if temp.right != nil:
            temp.right.p = node

        # Set the right child of the left child as the new node's right child
        temp.right = node

        # Set the parent of the left child to the node's parent
        temp.p = node.p

        # If the node's parent is nil, make the new left child the root
        if node.p == nil:
            self.root = temp
        elif node == node.p.right:
            node.p.right = temp
        else:
            node.p.left = temp

        # Set the new left child as the node's right child
        node.right = temp

        # Set the node as the new left child of the left child
        temp.p = node

    def print_in_order(self):
        self.print_tree(self.root)
        print()

# Main method to read keys from the standard input and insert them into the tree
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    rb_tree = RedBlackTree()

    # Insert n keys into the tree
    for i in range(1, n + 1):
        key = int(data[i])
        rb_tree.insert(key)

    # Print the in-order traversal of the tree
    print("In-order traversal:")
    rb_tree.print_in_order()

# <END-OF-CODE>
