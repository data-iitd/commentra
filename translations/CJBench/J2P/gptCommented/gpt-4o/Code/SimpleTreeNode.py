class Node:
    def __init__(self, data):
        # Node data
        self.data = data
        # References to left and right child nodes
        self.left_node = None
        self.right_node = None

    # Getter method for node data
    def get_data(self):
        return self.data

    # Setter method for the left child node
    def set_left_node(self, left_node):
        self.left_node = left_node

    # Setter method for the right child node
    def set_right_node(self, right_node):
        self.right_node = right_node

    # Getter method for the left child node
    def get_left_node(self):
        return self.left_node

    # Getter method for the right child node
    def get_right_node(self):
        return self.right_node

    # Method to check if the current node is a leaf node
    def is_leaf_node(self):
        return self.left_node is None and self.right_node is None


def pre_order_traversal(root):
    # Base case: if the current node is None, return
    if root is None:
        return
    # Print the data of the current node
    print(root.get_data(), end=" ")
    # Recursively traverse the left subtree
    pre_order_traversal(root.get_left_node())
    # Recursively traverse the right subtree
    pre_order_traversal(root.get_right_node())


def main():
    # Read the number of nodes
    n = int(input())
    # Create a list to hold the nodes
    nodes = [None] * (n + 1)

    # Initialize the nodes with their respective data
    for i in range(1, n + 1):
        nodes[i] = Node(i)

    # Read parent-child relationships and set the left or right child accordingly
    for _ in range(n - 1):
        parent, child, direction = input().split()
        parent = int(parent)
        child = int(child)
        if direction == "L":
            # Set the left child node
            nodes[parent].set_left_node(nodes[child])
        elif direction == "R":
            # Set the right child node
            nodes[parent].set_right_node(nodes[child])

    # Perform a pre-order traversal starting from the root node
    pre_order_traversal(nodes[1])


if __name__ == "__main__":
    main()

# <END-OF-CODE>
