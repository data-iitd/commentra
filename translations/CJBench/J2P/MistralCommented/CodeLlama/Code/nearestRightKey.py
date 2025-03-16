
import sys

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def main():
    # Initialize Scanner to read input
    sc = sys.stdin

    # Read the number of nodes in the tree
    n = int(sc.readline().strip())

    # Create a HashMap to store nodes in the tree
    nodeMap = {}

    # Initialize root node to None
    root = None

    # Read each node and create a new node if it doesn't exist in the map
    # Put the node in the map and set its left and right children if they exist
    for i in range(n):
        values = sc.readline().strip().split()
        value = int(values[0])
        left = int(values[1])
        right = int(values[2])

        # Create a new node if it doesn't exist in the map
        if value not in nodeMap:
            nodeMap[value] = Node(value)

        # Get the current node
        current = nodeMap[value]

        # If root is None, set the current node as the root
        if root is None:
            root = current

        # Set the left child of the current node if it exists
        if left != -1:
            if left not in nodeMap:
                nodeMap[left] = Node(left)
            current.left = nodeMap[left]

        # Set the right child of the current node if it exists
        if right != -1:
            if right not in nodeMap:
                nodeMap[right] = Node(right)
            current.right = nodeMap[right]

    # Read the input value x0
    inputX0 = int(sc.readline().strip())

    # Call the recursive function to find the nearest right key
    toPrint = main(root, inputX0)

    # Print the result
    if toPrint == 0:
        print("No nearest right key found.")
    else:
        print("Nearest Right Key:", toPrint)

    # Close the Scanner
    sc.close()

def main(root, x0):
    # Base case: if root is None, return 0
    if root is None:
        return 0

    # If the current node's data is greater than x0, search in the left subtree
    if root.data > x0:
        temp = main(root.left, x0)

        # If the left subtree doesn't have the answer, return the current node's data
        if temp == 0:
            return root.data

        # Otherwise, return the answer from the left subtree
        return temp

    # Otherwise, search in the right subtree
    return main(root.right, x0)

if __name__ == "__main__":
    main()

