
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

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

    def sort(self, unsortedArray):
        for element in unsortedArray:
            self.add(element)
        return self.inOrderTraversal()

class Main:
    def sort(self, unsortedArray):
        tree = BST()
        for element in unsortedArray:
            tree.add(element)
        return tree.inOrderTraversal()

if __name__ == "__main__":
    scanner = Scanner(System.in)
    treeSort = Main()
    type = scanner.nextInt()
    scanner.nextLine()
    n = scanner.nextInt()
    scanner.nextLine()
    if type == 1:
        array = []
        for i in range(n):
            array.append(scanner.nextInt())
        array = treeSort.sort(array)
        print("Sorted Array:")
        for num in array:
            print(num, end=" ")
    elif type == 2:
        array = []
        for i in range(n):
            array.append(scanner.nextLine())
        array = treeSort.sort(array)
        print("Sorted Array:")
        for str in array:
            print(str, end=" ")
    else:
        print("Invalid type entered.")
    scanner.close()

