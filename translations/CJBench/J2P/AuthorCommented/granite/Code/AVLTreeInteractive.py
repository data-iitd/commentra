
class Node:
    def __init__(self, key, parent=None):
        self.key = key
        self.parent = parent
        self.balance = 0
        self.height = 1
        self.left = None
        self.right = None

class AVLTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
        else:
            current = self.root
            parent = None
            while current is not None:
                parent = current
                if key < current.key:
                    current = current.left
                else:
                    current = current.right
            if key < parent.key:
                parent.left = Node(key, parent)
            else:
                parent.right = Node(key, parent)
            self.rebalance(parent)

    def delete(self, key):
        if self.root is None:
            return
        node = self.root
        child = self.root
        while child is not None:
            node = child
            child = None
            if key < node.key:
                child = node.left
            elif key > node.key:
                child = node.right
            if key == node.key:
                self.delete_node(node)
                return
        return

    def delete_node(self, node):
        if node.left is None and node.right is None:
            if node.parent is None:
                self.root = None
            else:
                parent = node.parent
                if parent.left == node:
                    parent.left = None
                else:
                    parent.right = None
                self.rebalance(parent)
        elif node.left is None:
            if node.parent is None:
                self.root = node.right
                node.right.parent = None
            else:
                parent = node.parent
                if parent.left == node:
                    parent.left = node.right
                    node.right.parent = parent
                else:
                    parent.right = node.right
                    node.right.parent = parent
            self.rebalance(parent)
        elif node.right is None:
            if node.parent is None:
                self.root = node.left
                node.left.parent = None
            else:
                parent = node.parent
                if parent.left == node:
                    parent.left = node.left
                    node.left.parent = parent
                else:
                    parent.right = node.left
                    node.left.parent = parent
            self.rebalance(parent)
        else:
            successor = self.find_successor(node)
            node.key = successor.key
            self.delete_node(successor)

    def find_successor(self, node):
        if node.right is not None:
            return self.find_minimum(node.right)
        else:
            parent = node.parent
            while parent is not None and node == parent.right:
                node = parent
                parent = parent.parent
            return parent

    def find_minimum(self, node):
        while node.left is not None:
            node = node.left
        return node

    def search(self, key):
        current = self.root
        while current is not None:
            if key == current.key:
                return True
            elif key < current.key:
                current = current.left
            else:
                current = current.right
        return False

    def display(self):
        self.display_helper(self.root)
        print()

    def display_helper(self, node):
        if node is not None:
            self.display_helper(node.left)
            print(node.key, end=" ")
            self.display_helper(node.right)

    def rebalance(self, node):
        self.set_balance(node)
        if node.balance == -2:
            if self.height(node.left.left) >= self.height(node.left.right):
                node = self.rotate_right(node)
            else:
                node = self.rotate_left_then_right(node)
        elif node.balance == 2:
            if self.height(node.right.right) >= self.height(node.right.left):
                node = self.rotate_left(node)
            else:
                node = self.rotate_right_then_left(node)
        if node.parent is not None:
            self.rebalance(node.parent)
        else:
            self.root = node

    def rotate_left(self, a):
        b = a.right
        b.parent = a.parent
        a.right = b.left
        if a.right is not None:
            a.right.parent = a
        b.left = a
        a.parent = b
        self.set_balance(a, b)
        return b

    def rotate_right(self, a):
        b = a.left
        b.parent = a.parent
        a.left = b.right
        if a.left is not None:
            a.left.parent = a
        b.right = a
        a.parent = b
        self.set_balance(a, b)
        return b

    def rotate_left_then_right(self, n):
        n.left = self.rotate_left(n.left)
        return self.rotate_right(n)

    def rotate_right_then_left(self, n):
        n.right = self.rotate_right(n.right)
        return self.rotate_left(n)

    def height(self, node):
        return -1 if node is None else node.height

    def set_balance(self, *nodes):
        for node in nodes:
            self.reheight(node)
            node.balance = self.height(node.right) - self.height(node.left)

    def reheight(self, node):
        if node is not None:
            node.height = 1 + max(self.height(node.left), self.height(node.right))

    if __name__ == "__main__":
        tree = AVLTree()
        commands = ["insert 10", "insert 20", "insert 30", "insert 40", "insert 50", "insert 60", "insert 70", "search 50", "search 80", "delete 50", "delete 70", "display", "exit"]
        for command in commands:
            parts = command.split()
            if parts[0] == "insert":
                tree.insert(int(parts[1]))
            elif parts[0] == "delete":
                tree.delete(int(parts[1]))
            elif parts[0] == "search":
                print("Found" if tree.search(int(parts[1])) else "Not Found")
            elif parts[0] == "display":
                tree.display()
            elif parts[0] == "exit":
                break

