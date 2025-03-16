
class Node(object):
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

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

class Main(object):
    def __init__(self):
        self.treeSort = BST()

    def sort(self, unsortedArray):
        for element in unsortedArray:
            self.treeSort.add(element)
        return self.treeSort.inOrderTraversal()

    def sort(self, unsortedList):
        for element in unsortedList:
            self.treeSort.add(element)
        return self.treeSort.inOrderTraversal()

if __name__ == "__main__":
    main = Main()
    type = int(raw_input())
    n = int(raw_input())
    if type == 1:
        array = [int(raw_input()) for i in range(n)]
        array = main.sort(array)
        print "Sorted Array:"
        for num in array:
            print num,
    elif type == 2:
        array = [raw_input() for i in range(n)]
        array = main.sort(array)
        print "Sorted Array:"
        for str in array:
            print str,
    else:
        print "Invalid type entered."

