
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def add(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self._add(self.root, data)

    def _add(self, node, data):
        if data < node.data:
            if node.left is None:
                node.left = Node(data)
            else:
                self._add(node.left, data)
        else:
            if node.right is None:
                node.right = Node(data)
            else:
                self._add(node.right, data)

    def remove(self, data):
        if self.root is None:
            print("No such data present in BST.")
            return
        self._remove(self.root, data)

    def _remove(self, node, data):
        if data < node.data:
            if node.left is None:
                print("No such data present in BST.")
                return
            else:
                self._remove(node.left, data)
        elif data > node.data:
            if node.right is None:
                print("No such data present in BST.")
                return
            else:
                self._remove(node.right, data)
        else:
            if node.left is None and node.right is None:
                node = None
            elif node.left is None:
                node = node.right
            elif node.right is None:
                node = node.left
            else:
                temp = self._findMin(node.right)
                node.data = temp.data
                self._remove(node.right, temp.data)

    def _findMin(self, node):
        while node.left is not None:
            node = node.left
        return node

    def find(self, data):
        if self.root is None:
            print("No such data present in BST.")
            return False
        result = self._find(self.root, data)
        if result:
            print(data, "is present in the BST.")
        else:
            print(data, "is not found.")
        return result

    def _find(self, node, data):
        if data < node.data:
            if node.left is None:
                return False
            else:
                return self._find(node.left, data)
        elif data > node.data:
            if node.right is None:
                return False
            else:
                return self._find(node.right, data)
        else:
            return True

    def inOrderTraversal(self, node):
        if node is not None:
            self.inOrderTraversal(node.left)
            print(node.data, end=" ")
            self.inOrderTraversal(node.right)

    def getRoot(self):
        return self.root

if __name__ == "__main__":
    bst = BST()
    n = int(input())
    for i in range(n):
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
            bst.inOrderTraversal(bst.getRoot())
            print()
        else:
            print("Invalid choice. Try again.")

