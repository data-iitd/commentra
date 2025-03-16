
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

def sort(unsortedArray):
    tree = BST()
    for element in unsortedArray:
        tree.add(element)
    return tree.inOrderTraversal()

def main():
    type = int(input("Enter the type of input (1 for Array, 2 for List): "))
    n = int(input("Enter the size of the input: "))
    if type == 1:
        array = [int(input()) for i in range(n)]
        sortedArray = sort(array)
        print("Sorted Array:", end=" ")
        for num in sortedArray:
            print(num, end=" ")
    elif type == 2:
        array = [input() for i in range(n)]
        sortedArray = sort(array)
        print("Sorted Array:", end=" ")
        for str in sortedArray:
            print(str, end=" ")
    else:
        print("Invalid type entered.")

if __name__ == "__main__":
    main()

