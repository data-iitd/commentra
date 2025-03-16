
class Node:
    def __init__(self, data):
        self.data = data
        self.child = []

class Main:
    def __init__(self, scn):
        self.root = self.createTree(None, 0, scn)

    def createTree(self, parent, childIndex, scanner):
        if parent is None:
            print("Enter root's data:")
        else:
            print("Enter data for child " + str(childIndex + 1) + " of " + str(parent.data) + ":")
        node = Node(scanner.nextInt())
        print("Enter the number of children for " + str(node.data) + ":")
        numChildren = scanner.nextInt()
        for i in range(numChildren):
            child = self.createTree(node, i, scanner)
            node.child.append(child)
        return node

    def display(self):
        self.displayTree(self.root)

    def displayTree(self, node):
        print(str(node.data) + " => ", end="")
        for child in node.child:
            print(str(child.data) + " ", end="")
        print(".")
        for child in node.child:
            self.displayTree(child)

    def size(self):
        return self.sizeHelper(self.root)

    def sizeHelper(self, node):
        size = 0
        for child in node.child:
            size += self.sizeHelper(child)
        return size + 1

    def max(self):
        return self.maxHelper(self.root)

    def maxHelper(self, node):
        max = node.data
        for child in node.child:
            max = max(max, self.maxHelper(child))
        return max

    def height(self):
        return self.heightHelper(self.root) - 1

    def heightHelper(self, node):
        height = 0
        for child in node.child:
            height = max(height, self.heightHelper(child))
        return height + 1

    def find(self, value):
        return self.findHelper(self.root, value)

    def findHelper(self, node, value):
        if node.data == value:
            return True
        for child in node.child:
            if self.findHelper(child, value):
                return True
        return False

    def levelOrder(self):
        queue = []
        queue.append(self.root)
        while len(queue) > 0:
            current = queue.pop(0)
            print(str(current.data) + " ", end="")
            queue.extend(current.child)
        print()

if __name__ == "__main__":
    scn = Scanner(sys.stdin)
    tree = Main(scn)
    print("\nTree Display:")
    tree.display()
    print("\nSize of the tree: " + str(tree.size()))
    print("Maximum value in the tree: " + str(tree.max()))
    print("Height of the tree: " + str(tree.height()))
    print("\nEnter a value to search:")
    searchValue = scn.nextInt()
    print("Is value present: " + str(tree.find(searchValue)))
    print("\nLevel Order Traversal:")
    tree.levelOrder()
