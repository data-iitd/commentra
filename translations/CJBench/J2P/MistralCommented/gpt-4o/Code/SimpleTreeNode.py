class Node:  # Defining a class named Node for creating tree nodes
    def __init__(self, data):  # Constructor for initializing a new node with given data
        self.data = data  # Assigning data to the node
        self.left_node = None  # Initializing left child node as None
        self.right_node = None  # Initializing right child node as None

    def is_leaf_node(self):  # Method for checking if the current node is a leaf node (has no children)
        return self.left_node is None and self.right_node is None


def pre_order_traversal(root):  # Recursive function for performing pre-order traversal of the tree
    if root is None:  # Base case: if the root is None, return
        return

    print(root.data, end=" ")  # Printing the data of the current node
    pre_order_traversal(root.left_node)  # Recursively traversing the left subtree
    pre_order_traversal(root.right_node)  # Recursively traversing the right subtree


def main():  # Main function for reading input and performing tree construction
    n = int(input())  # Reading the number of nodes in the tree from the console
    nodes = [None] * (n + 1)  # Creating a list of size n+1 to store the tree nodes

    for i in range(1, n + 1):  # Loop for creating new nodes and initializing them with their data
        nodes[i] = Node(i)

    for _ in range(n - 1):  # Loop for reading the parent-child relationships and connecting the nodes
        parent, child, direction = input().split()  # Reading the parent node index, child node index, and direction
        parent = int(parent)
        child = int(child)

        if direction == "L":  # If the relationship is left, set the left child of the parent node
            nodes[parent].left_node = nodes[child]
        elif direction == "R":  # If the relationship is right, set the right child of the parent node
            nodes[parent].right_node = nodes[child]

    pre_order_traversal(nodes[1])  # Performing pre-order traversal of the tree starting from the root node


if __name__ == "__main__":  # Entry point of the program
    main()  # Calling the main function

# <END-OF-CODE>
