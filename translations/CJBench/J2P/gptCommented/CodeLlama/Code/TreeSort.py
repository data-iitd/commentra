
# Node class representing each node in the Binary Search Tree (BST)
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Binary Search Tree class
class BST:
    def __init__(self):
        self.root = None

    # Public method to add data to the BST
    def add(self, data):
        self.root = self.addRecursive(self.root, data)

    # Private recursive method to add data to the BST
    def addRecursive(self, node, data):
        if node is None:
            return Node(data)
        if data < node.data:
            node.left = self.addRecursive(node.left, data)
        else:
            node.right = self.addRecursive(node.right, data)
        return node

    # Method to perform in-order traversal of the BST
    def inOrderTraversal(self):
        result = []
        self.inOrderTraversalRecursive(self.root, result)
        return result

    # Private recursive method for in-order traversal
    def inOrderTraversalRecursive(self, node, result):
        if node is not None:
            self.inOrderTraversalRecursive(node.left, result)
            result.append(node.data)
            self.inOrderTraversalRecursive(node.right, result)

    # Method to sort an array using BST
    def sort(self, unsortedArray):
        for element in unsortedArray:
            self.add(element)
        return self.inOrderTraversal()

    # Method to sort a list using BST
    def sortList(self, unsortedList):
        for element in unsortedList:
            self.add(element)
        return self.inOrderTraversal()

# Main method to execute the program
def main():
    scanner = Scanner(System.in)
    treeSort = BST()
    type = scanner.nextInt()
    scanner.nextLine()
    n = scanner.nextInt()
    scanner.nextLine()

    # Check if the input type is for an Integer array
    if type == 1:
        array = []
        for i in range(n):
            array.append(scanner.nextInt())
        array = treeSort.sort(array)
        print("Sorted Array:")
        for num in array:
            print(num, end=" ")

    # Check if the input type is for a String array
    elif type == 2:
        array = []
        for i in range(n):
            array.append(scanner.nextLine())
        array = treeSort.sort(array)
        print("Sorted Array:")
        for str in array:
            print(str, end=" ")

    # Handle invalid input type
    else:
        print("Invalid type entered.")

    scanner.close()

if __name__ == "__main__":
    main()

