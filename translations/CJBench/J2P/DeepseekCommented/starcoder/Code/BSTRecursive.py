
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def getRoot(self):
        return self.root

    def insert(self, data):
        if self.root == None:
            self.root = Node(data)
        else:
            self.insertNode(self.root, data)

    def insertNode(self, node, data):
        if data < node.data:
            if node.left == None:
                node.left = Node(data)
            else:
                self.insertNode(node.left, data)
        else:
            if node.right == None:
                node.right = Node(data)
            else:
                self.insertNode(node.right, data)

    def delete(self, data):
        if self.root == None:
            print("No such data present in BST.")
            return
        else:
            self.root = self.deleteNode(self.root, data)

    def deleteNode(self, node, data):
        if node == None:
            return None
        if data < node.data:
            node.left = self.deleteNode(node.left, data)
        elif data > node.data:
            node.right = self.deleteNode(node.right, data)
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
                node.right = self.deleteNode(node.right, temp.data)
        return node

    def findMin(self, node):
        while node.left!= None:
            node = node.left
        return node

    def search(self, data):
        if self.root == None:
            return False
        else:
            return self.searchNode(self.root, data)

    def searchNode(self, node, data):
        if node == None:
            return False
        if data < node.data:
            return self.searchNode(node.left, data)
        elif data > node.data:
            return self.searchNode(node.right, data)
        else:
            return True

    def inOrderTraversal(self, node):
        if node!= None:
            self.inOrderTraversal(node.left)
            print(node.data, end=" ")
            self.inOrderTraversal(node.right)

if __name__ == "__main__":
    bst = BinarySearchTree()
    n = int(input())
    for i in range(n):
        choice = int(input())
        if choice == 1:
            data = int(input())
            bst.insert(data)
        elif choice == 2:
            data = int(input())
            bst.delete(data)
        elif choice == 3:
            data = int(input())
            bst.search(data)
        elif choice == 4:
            bst.inOrderTraversal(bst.getRoot())
            print()
        else:
            print("Invalid choice. Try again.")

