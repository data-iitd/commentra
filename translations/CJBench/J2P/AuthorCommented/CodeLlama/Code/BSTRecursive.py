
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BST:
    def __init__(self):
        self.root = None

    def insert(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self._insert(self.root, data)

    def _insert(self, node, data):
        if data < node.data:
            if node.left is None:
                node.left = Node(data)
            else:
                self._insert(node.left, data)
        else:
            if node.right is None:
                node.right = Node(data)
            else:
                self._insert(node.right, data)

    def remove(self, data):
        if self.root is None:
            print("No such data present in BST.")
        else:
            self.root = self._delete(self.root, data)

    def _delete(self, node, data):
        if node is None:
            print("No such data present in BST.")
            return None

        if data < node.data:
            node.left = self._delete(node.left, data)
        elif data > node.data:
            node.right = self._delete(node.right, data)
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
                node.right = self._delete(node.right, temp.data)
        return node

    def findMin(self, node):
        while node.left is not None:
            node = node.left
        return node

    def find(self, data):
        result = self._search(self.root, data)
        if result:
            print(data, "is present in the BST.")
        else:
            print(data, "is not found.")
        return result

    def _search(self, node, data):
        if node is None:
            return False
        if data < node.data:
            return self._search(node.left, data)
        elif data > node.data:
            return self._search(node.right, data)
        else:
            return True

    def inOrderTraversal(self, node):
        if node is not None:
            self.inOrderTraversal(node.left)
            print(node.data, end=" ")
            self.inOrderTraversal(node.right)


if __name__ == "__main__":
    bst = BST()
    n = int(input())

    for i in range(n):
        choice = int(input())

        if choice == 1:
            insertValue = int(input())
            bst.insert(insertValue)
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

    print("