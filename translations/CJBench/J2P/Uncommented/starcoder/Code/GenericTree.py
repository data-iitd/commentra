import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;
class Main:
    class Node:
        def __init__(self, data):
            self.data = data
            self.child = []
    def __init__(self, scn):
        self.root = self.createTree(None, 0, scn)
    def createTree(self, parent, childIndex, scanner):
        if parent == None:
            print("Enter root's data:")
        else:
            print("Enter data for child " + str(childIndex + 1) + " of " + parent.data + ":")
        node = Main.Node(scanner.nextInt())
        print("Enter the number of children for " + str(node.data) + ":")
        numChildren = scanner.nextInt()
        for i in range(numChildren):
            child = self.createTree(node, i, scanner)
            node.child.append(child)
        return node
    def display(self):
        self.displayTree(self.root)
    def displayTree(self, node):
        print(node.data, "=>", end=" ")
        for child in node.child:
            print(child.data, end=" ")
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
            max = max if max > child.data else child.data
        return max
    def height(self):
        return self.heightHelper(self.root) - 1
    def heightHelper(self, node):
        height = 0
        for child in node.child:
            height = height if height > self.heightHelper(child) else self.heightHelper(child)
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
        queue = LinkedList()
        queue.add(self.root)
        while not queue.isEmpty():
            current = queue.poll()
            print(current.data, end=" ")
            queue.addAll(current.child)
        print()
if __name__ == "__main__":
    scn = Scanner(System.in)
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
