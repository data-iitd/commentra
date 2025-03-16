

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinarySearchTree:
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
        elif data > node.data:
            if node.right is None:
                node.right = Node(data)
            else:
                self._insert(node.right, data)

    def delete(self, data):
        self.root = self._delete(self.root, data)

    def _delete(self, node, data):
        if node is None:
            return node
        elif data < node.data:
            node.left = self._delete(node.left, data)
        elif data > node.data:
            node.right = self._delete(node.right, data)
        else:
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left
            temp = self._find_min(node.right)
            node.data = temp.data
            node.right = self._delete(node.right, temp.data)
        return node

    def _find_min(self, node):
        while node.left is not None:
            node = node.left
        return node

    def search(self, data):
        if self._search(self.root, data):
            print(f"{data} is present in the BST.")
        else:
            print(f"{data} is not found.")

    def _search(self, node, data):
        if node is None:
            return False
        elif data < node.data:
            return self._search(node.left, data)
        elif data > node.data:
            return self._search(node.right, data)
        else:
            return True

    def in_order_traversal(self, node):
        if node is not None:
            self.in_order_traversal(node.left)
            print(node.data, end=" ")
            self.in_order_traversal(node.right)

if __name__ == "__main__":
    n = int(input("Enter the number of operations: "))
    bst = BinarySearchTree()
    for _ in range(n):
        choice = int(input("Enter the choice (1 for insert, 2 for delete, 3 for search, 4 for display): "))
        if choice == 1:
            data = int(input("Enter the data to be inserted: "))
            bst.insert(data)
        elif choice == 2:
            data = int(input("Enter the data to be deleted: "))
            bst.delete(data)
        elif choice == 3:
            data = int(input("Enter the data to be searched: "))
            bst.search(data)
        elif choice == 4:
            bst.in_order_traversal(bst.root)
            print()
        else:
            print("Invalid choice. Try again.")

