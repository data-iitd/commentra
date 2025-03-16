
import sys
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
class Main:
    def __init__(self):
        self.root = None
    def getRoot(self):
        return self.root
    def insert(self, node, data):
        if node == None:
            node = Node(data)
        elif data < node.data:
            node.left = self.insert(node.left, data)
        elif data > node.data:
            node.right = self.insert(node.right, data)
        return node
    def add(self, data):
        self.root = self.insert(self.root, data)
    def delete(self, node, data):
        if node == None:
            print("No such data present in BST.")
            return None
        if data < node.data:
            node.left = self.delete(node.left, data)
        elif data > node.data:
            node.right = self.delete(node.right, data)
        else:
            if node.left == None and node.right == None:
                return None
            elif node.left == None:
                return node.right
            elif node.right == None:
                return node.left
            else:
                temp = self.findMin(node.right)
                node.data = temp.data
                node.right = self.delete(node.right, temp.data)
        return node
    def remove(self, data):
        self.root = self.delete(self.root, data)
    def findMin(self, node):
        while node.left!= None:
            node = node.left
        return node
    def search(self, node, data):
        if node == None:
            return False
        if data < node.data:
            return self.search(node.left, data)
        elif data > node.data:
            return self.search(node.right, data)
        else:
            return True
    def find(self, data):
        result = self.search(self.root, data)
        if result:
            print(data, "is present in the BST.")
        else:
            print(data, "is not found.")
        return result
    def inOrderTraversal(self, node):
        if node!= None:
            self.inOrderTraversal(node.left)
            print(node.data, end=" ")
            self.inOrderTraversal(node.right)
    def main(self):
        n = int(sys.stdin.readline())
        for i in range(n):
            choice = int(sys.stdin.readline())
            if choice == 1:
                data = int(sys.stdin.readline())
                self.add(data)
            elif choice == 2:
                data = int(sys.stdin.readline())
                self.remove(data)
            elif choice == 3:
                data = int(sys.stdin.readline())
                self.find(data)
            elif choice == 4:
                print("In-order Traversal of BST:")
                self.inOrderTraversal(self.getRoot())
                print()
            else:
                print("Invalid choice. Try again.")
if __name__ == "__main__":
    main = Main()
    main.main()

