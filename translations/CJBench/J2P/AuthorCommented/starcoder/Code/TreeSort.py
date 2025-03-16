
# Node class for BST
class Node(object):
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


# Generic BST class
class BST(object):
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
        self.inOrderTraversal(self.root, result)
        return result

    def inOrderTraversal(self, node, result):
        if node is not None:
            self.inOrderTraversal(node.left, result)
            result.append(node.data)
            self.inOrderTraversal(node.right, result)


# Sort method for arrays
def sort(unsortedArray):
    tree = BST()
    for element in unsortedArray:
        tree.add(element)
    return tree.inOrderTraversal()


# Sort method for lists
def sort(unsortedList):
    tree = BST()
    for element in unsortedList:
        tree.add(element)
    return tree.inOrderTraversal()


# Main method
if __name__ == '__main__':
    import sys

    scanner = sys.stdin
    treeSort = Main()

    type = int(scanner.readline())
    scanner.readline()  # Consume newline

    n = int(scanner.readline())
    scanner.readline()  # Consume newline

    if type == 1:
        array = [None] * n

        for i in range(n):
            array[i] = int(scanner.readline())
        array = sort(array)
        print("Sorted Array:")
        for num in array:
            print(num, end=' ')
    elif type == 2:
        array = [None] * n

        for i in range(n):
            array[i] = scanner.readline()
        array = sort(array)
        print("Sorted Array:")
        for str in array:
            print(str, end=' ')
    else:
        print("Invalid type entered.")
    scanner.close()

