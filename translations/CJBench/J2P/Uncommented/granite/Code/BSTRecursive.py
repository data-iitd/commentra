

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Main:
    def __init__(self):
        self.root = None

    def insert(self, node, data):
        if node is None:
            node = Node(data)
        elif data < node.data:
            node.left = self.insert(node.left, data)
        else:
            node.right = self.insert(node.right, data)
        return node

    def add(self, data):
        self.root = self.insert(self.root, data)

    def delete(self, node, data):
        if node is None:
            print("No such data present in BST.")
            return None
        if data < node.data:
            node.left = self.delete(node.left, data)
        elif data > node.data:
            node.right = self.delete(node.right, data)
        else:
            if node.left is None and node.right is None: 
                return None
            elif node.left is None: 
                return node.right
            elif node.right is None: 
                return node.left
            else: 
                temp = self.findMin(node.right)
                node.data = temp.data
                node.right = self.delete(node.right, temp.data)
        return node

    def remove(self, data):
        self.root = self.delete(self.root, data)

    def findMin(self, node):
        while node.left is not None:
            node = node.left
        return node

    def search(self, node, data):
        if node is None:
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
            print(f"{data} is present in the BST.")
        else:
            print(f"{data} is not found.")
        return result

    def inOrderTraversal(self, node):
        if node is not None:
            self.inOrderTraversal(node.left)
            print(node.data, end=" ")
            self.inOrderTraversal(node.right)

if __name__ == "__main__":
    import sys
    n = int(input())
    bst = Main()
    for _ in range(n):
        choice = int(input())
        if choice == 1: 
            insertValue = int(input())
            bst.add(insertValue)
        elif choice == 2: 
            deleteValue = int(input())
            bst.remove(deleteValue)
        elif choice == 3: 
            searchValue = int(input())
            bst.find(searchValue)
        elif choice == 4: 
            print("In-order Traversal of BST:")
            bst.inOrderTraversal(bst.root)
            print()
        else:
            print("Invalid choice. Try again.")
