class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Main:
    def __init__(self):
        self.root = None

    def get_root(self):
        return self.root

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
            if node.left is None and node.right is None:
                return None
            elif node.left is None:
                return node.right
            elif node.right is None:
                return node.left
            else:
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
    input = sys.stdin.read
    data = input().splitlines()
    
    bst = Main()
    n = int(data[0])
    
    for i in range(1, n + 1):
        choice = int(data[i].split()[0])
        if choice == 1:
            insert_value = int(data[i].split()[1])
            bst.add(insert_value)
        elif choice == 2:
            delete_value = int(data[i].split()[1])
            bst.remove(delete_value)
        elif choice == 3:
            search_value = int(data[i].split()[1])
            bst.find(search_value)
        elif choice == 4:
            print("In-order Traversal of BST:")
            bst.in_order_traversal(bst.get_root())
            print()
        else:
            print("Invalid choice. Try again.")

# <END-OF-CODE>
