class Node:
    def __init__(self, key):
        self.key = key  # The key value of the node
        self.parent = None  # Pointer to the parent node
        self.left = None  # Pointer to the left child node
        self.right = None  # Pointer to the right child node


class Tree:
    def __init__(self):
        self.root = None  # Pointer to the root node of the tree

    def insert(self, key):
        # If the tree is empty, create a new root node
        if self.root is None:
            self.root = Node(key)
            return

        current_node = self.root
        prev_node = None
        # Traverse the tree to find the correct position for the new key
        while current_node is not None:
            prev_node = current_node
            if current_node.key < key:
                current_node = current_node.right  # Move to the right child
            else:
                current_node = current_node.left  # Move to the left child

        # Create a new node for the key and set its parent
        new_node = Node(key)
        new_node.parent = prev_node
        # Attach the new node to the correct position in the tree
        if prev_node.key < key:
            prev_node.right = new_node  # Insert as right child
        else:
            prev_node.left = new_node  # Insert as left child

    def print_tree(self):
        if self.root is None:
            print("")
            print("")
        else:
            # Print inorder traversal
            print(" " + " ".join(map(str, self.visit_inorder(self.root, []))))
            # Print preorder traversal
            print(" " + " ".join(map(str, self.visit_preorder(self.root, []))))

    def visit_preorder(self, node, acc):
        if node is None:
            return acc  # Return accumulated keys if node is None
        acc.append(node.key)  # Add the current node's key
        if node.left is not None:
            self.visit_preorder(node.left, acc)  # Traverse left subtree
        if node.right is not None:
            self.visit_preorder(node.right, acc)  # Traverse right subtree
        return acc

    def visit_inorder(self, node, acc):
        if node is None:
            return acc  # Return accumulated keys if node is None
        if node.left is not None:
            self.visit_inorder(node.left, acc)  # Traverse left subtree
        acc.append(node.key)  # Add the current node's key
        if node.right is not None:
            self.visit_inorder(node.right, acc)  # Traverse right subtree
        return acc


def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    n = int(data[0])  # Read the number of commands
    tree = Tree()  # Initialize a new binary tree

    # Process each command
    for i in range(1, n + 1):
        command = data[i].split()
        if command[0] == "insert":
            key = int(command[1])  # Read the key to insert
            tree.insert(key)  # Insert the key into the tree
        elif command[0] == "print":
            tree.print_tree()  # Print the tree's keys
        else:
            raise ValueError("unknown command: " + command[0])  # Handle unknown commands


if __name__ == "__main__":
    main()

# <END-OF-CODE>
