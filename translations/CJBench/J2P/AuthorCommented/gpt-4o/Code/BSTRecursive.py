class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, node, data):
        if node is None:
            return Node(data)
        elif data < node.data:
            node.left = self.insert(node.left, data)
        elif data > node.data:
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
            # Node to delete found
            if node.left is None and node.right is None:  # Leaf node
                return None
            elif node.left is None:  # Only right child
                return node.right
            elif node.right is None:  # Only left child
                return node.left
            else:  # Both children
                temp = self.find_min(node.right)
                node.data = temp.data
                node.right = self.delete(node.right, temp.data)

        return node

    def remove(self, data):
        self.root = self.delete(self.root, data)

    def find_min(self, node):
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

    def in_order_traversal(self, node):
        if node is not None:
            self.in_order_traversal(node.left)
            print(node.data, end=" ")
            self.in_order_traversal(node.right)


if __name__ == "__main__":
    import sys

    bst = BinarySearchTree()
    n = int(sys.stdin.readline().strip())

    for _ in range(n):
        choice = int(sys.stdin.readline().strip())

        if choice == 1:  # Insert
            insert_value = int(sys.stdin.readline().strip())
            bst.add(insert_value)

        elif choice == 2:  # Delete
            delete_value = int(sys.stdin.readline().strip())
            bst.remove(delete_value)

        elif choice == 3:  # Search
            search_value = int(sys.stdin.readline().strip())
            bst.find(search_value)

        elif choice == 4:  # Display
            print("In-order Traversal of BST:")
            bst.in_order_traversal(bst.root)
            print()

        else:
            print("Invalid choice. Try again.")

# <END-OF-CODE>
