
import sys

# Node class for BST
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Generic BST class
class BST:
    def __init__(self):
        self.root = None

    def add(self, data):
        self.root = self.addRecursive(self.root, data)

    def addRecursive(self, node, data):
        if node is None:
            return Node(data)
        if data < node.data:
            node.left = self.addRecursive(node.left, data)
        else:
            node.right = self.addRecursive(node.right, data)
        return node

    def inOrderTraversal(self):
        result = []
        self.inOrderTraversalRecursive(self.root, result)
        return result

    def inOrderTraversalRecursive(self, node, result):
        if node is not None:
            self.inOrderTraversalRecursive(node.left, result)
            result.append(node.data)
            self.inOrderTraversalRecursive(node.right, result)

# Sort method for arrays
def sort(unsortedArray):
    tree = BST()
    for element in unsortedArray:
        tree.add(element)
    sortedList = tree.inOrderTraversal()
    return sortedList

# Sort method for lists
def sort(unsortedList):
    tree = BST()
    for element in unsortedList:
        tree.add(element)
    return tree.inOrderTraversal()

# Main method
def main():
    type = int(sys.stdin.readline())
    n = int(sys.stdin.readline())

    if type == 1:
        array = [int(i) for i in sys.stdin.readline().split()]
        array = sort(array)
        print("Sorted Array:")
        for num in array:
            print(num, end=" ")
    elif type == 2:
        array = [str(i) for i in sys.stdin.readline().split()]
        array = sort(array)
        print("Sorted Array:")
        for str in array:
            print(str, end=" ")
    else:
        print("Invalid type entered.")

if __name__ == "__main__":
    main()

