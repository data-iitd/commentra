
import sys

# This program builds a binary tree from user input and finds the nearest key
# on the right side of a given input key (x0) in the binary tree.

# Class representing a node in the binary tree.
class NRKTree:
    def __init__(self, x):
        self.left = None
        self.right = None
        self.data = x

# Finds the nearest key on the right side of a given key (x0) in the binary tree.
#
# @param root The root node of the binary tree.
# @param x0   The input key to find the nearest right key.
# @return The nearest right key if found, otherwise 0.
def Main(root, x0):
    # Check whether tree is empty
    if root == None:
        return 0
    else:
        if root.data > x0:
            # Go left
            temp = Main(root.left, x0)
            if temp == 0:
                return root.data
            return temp
        else:
            # Go right
            return Main(root.right, x0)

# Main program
if __name__ == "__main__":
    n = int(sys.stdin.readline())

    nodeMap = {}
    root = None

    for i in range(n):
        value = int(sys.stdin.readline())
        left = int(sys.stdin.readline())
        right = int(sys.stdin.readline())

        if value not in nodeMap:
            nodeMap[value] = NRKTree(value)
        current = nodeMap[value]

        if root == None:
            root = current # Assign the first node as the root

        if left!= -1:
            if left not in nodeMap:
                nodeMap[left] = NRKTree(left)
            current.left = nodeMap[left]
        if right!= -1:
            if right not in nodeMap:
                nodeMap[right] = NRKTree(right)
            current.right = nodeMap[right]

    inputX0 = int(sys.stdin.readline())

    toPrint = Main(root, inputX0)
    if toPrint == 0:
        print("No nearest right key found.")
    else:
        print("Nearest Right Key: " + str(toPrint))

