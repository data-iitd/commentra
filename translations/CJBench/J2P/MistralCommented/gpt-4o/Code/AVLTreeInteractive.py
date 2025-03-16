class Node:
    def __init__(self, key, parent=None):
        self.key = key
        self.balance = 0  # Balance factor of this node
        self.height = 0  # Height of this node
        self.left = None  # Left child node
        self.right = None  # Right child node
        self.parent = parent  # Parent node


class AVLTree:
    def __init__(self):
        self.root = None  # Declare a private reference to the root node

    def insert(self, key):
        if self.root is None:  # If the tree is empty, create a new root node
            self.root = Node(key)
        else:
            n = self.root  # Initialize a reference to the current node
            parent = None  # Initialize a reference to the parent node

            # Perform a standard tree traversal to find the insertion point
            while True:
                if n.key == key:
                    return False  # If the key already exists in the tree, return false
                parent = n  # Update the parent reference
                go_left = n.key > key  # Determine whether to go left or right
                n = n.left if go_left else n.right  # Move to the next node accordingly

                if n is None:  # If we reached an empty node, insert the new node here
                    if go_left:
                        parent.left = Node(key, parent)
                    else:
                        parent.right = Node(key, parent)
                    self.rebalance(parent)  # Rebalance the tree after insertion
                    break
        return True  # Return true to indicate a successful insertion

    def delete(self, del_key):
        if self.root is None:  # If the tree is empty, do nothing
            return
        node = self.root  # Initialize a reference to the current node
        child = self.root  # Initialize a reference to the child node

        # Perform a standard tree traversal to find the node to be deleted
        while child is not None:
            node = child  # Update the current node reference
            child = node.right if del_key >= node.key else node.left  # Move to the next node accordingly

            if del_key == node.key:  # If we found the node to be deleted
                self.delete_node(node)  # Call the delete_node method to perform the deletion
                return

    def delete_node(self, node):
        if node.left is None and node.right is None:  # If the node is a leaf node
            if node.parent is None:  # If the root node is being deleted
                self.root = None
            else:
                parent = node.parent  # Update the parent reference
                if parent.left == node:  # Determine which child the deleted node was
                    parent.left = None
                else:
                    parent.right = None
                self.rebalance(parent)  # Rebalance the tree after deletion
            return

        child = None  # Initialize a reference to the child node
        if node.left is not None:  # If the node has a left child
            child = node.left  # Set the child reference to the left child

            # Find the smallest node in the right subtree and copy its key to the node to be deleted
            while child.right is not None:
                child = child.right
            node.key = child.key
        else:  # If the node has a right child
            child = node.right  # Set the child reference to the right child

            # Find the smallest node in the left subtree and copy its key to the node to be deleted
            while child.left is not None:
                child = child.left
            node.key = child.key

        # Recursively delete the child node
        self.delete_node(child)

    def search(self, key):
        result = self.search_helper(self.root, key)  # Call the search_helper method to perform the search
        return result is not None  # Return true if the key was found, false otherwise

    def search_helper(self, root, key):
        if root is None or root.key == key:  # If the tree is empty or the key was found
            return root
        return self.search_helper(root.left, key) if key < root.key else self.search_helper(root.right, key)  # Recursively search the left or right subtree

    def display(self):
        self.display_helper(self.root)  # Call the display_helper method to perform the display

    def display_helper(self, node):
        if node is not None:  # If the node is not null
            self.display_helper(node.left)  # Recursively display the left subtree
            print(node.key, end=" ")  # Print the key of the current node
            self.display_helper(node.right)  # Recursively display the right subtree

    def rebalance(self, n):
        self.set_balance(n)  # Calculate the balance factors of all nodes in the tree

        if n.balance == -2:  # If the balance factor of the current node is -2 (left-heavy)
            if self.height(n.left.left) >= self.height(n.left.right):  # If the left child is also left-heavy
                n = self.rotate_right(n)  # Perform a right rotation
            else:  # If the left child is right-heavy
                n = self.rotate_left_then_right(n)  # Perform a left rotation followed by a right rotation
        elif n.balance == 2:  # If the balance factor of the current node is 2 (right-heavy)
            if self.height(n.right.right) >= self.height(n.right.left):  # If the right child is also right-heavy
                n = self.rotate_left(n)  # Perform a left rotation
            else:  # If the right child is left-heavy
                n = self.rotate_right_then_left(n)  # Perform a right rotation followed by a left rotation

        if n.parent is not None:  # If the current node has a parent
            self.rebalance(n.parent)  # Recursively rebalance the parent node
        else:  # If the current node is the root
            self.root = n  # Update the root reference

    def rotate_right(self, a):
        b = a.left  # Set the right child as the new root
        b.parent = a.parent  # Update the parent reference of the new root
        a.left = b.right  # Set the left child of the old root to the right child of the new root

        if a.left is not None:  # If the old root has a left child
            a.left.parent = a  # Set the parent reference of the left child

        b.right = a  # Set the right child of the new root to the old root
        a.parent = b  # Set the parent reference of the old root to the new root

        self.set_balance(a, b)  # Recalculate the balance factors
        return b  # Return the new root

    def rotate_left(self, a):
        b = a.right  # Set the left child as the new root
        b.parent = a.parent  # Update the parent reference of the new root
        a.right = b.left  # Set the right child of the old root to the left child of the new root

        if a.right is not None:  # If the old root has a right child
            a.right.parent = a  # Set the parent reference of the right child

        b.left = a  # Set the left child of the new root to the old root
        a.parent = b  # Set the parent reference of the old root to the new root

        self.set_balance(a, b)  # Recalculate the balance factors
        return b  # Return the new root

    def rotate_left_then_right(self, n):
        n.left = self.rotate_left(n.left)  # Perform a left rotation on the left child
        return self.rotate_right(n)  # Perform a right rotation on the new root

    def height(self, node):
        return -1 if node is None else node.height  # Return the height if it's already calculated, or calculate it and store it

    def set_balance(self, *nodes):
        for n in nodes:  # Iterate through all the nodes
            self.reheight(n)  # Recalculate the height
            n.balance = self.height(n.right) - self.height(n.left)  # Calculate the balance factor

    def reheight(self, node):
        if node is not None:  # If the node is not null
            node.height = 1 + max(self.height(node.left), self.height(node.right))  # Set the height based on the heights of its children

    @staticmethod
    def main():
        tree = AVLTree()  # Create a new instance of AVLTree
        # Example usage
        tree.insert(10)
        tree.insert(20)
        tree.insert(30)
        tree.display()  # Display the tree contents
        print()
        tree.delete(20)
        tree.display()  # Display the tree contents after deletion
        print()


if __name__ == "__main__":
    AVLTree.main()

# <END-OF-CODE>
