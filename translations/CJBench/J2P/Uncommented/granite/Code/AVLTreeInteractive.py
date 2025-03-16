
class Node:
    def __init__(self, key, parent):
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
            self.root = Node(key, None)
        else:
            n = self.root
            parent = n
            while True:
                if n.key == key:
                    return False
                parent = n
                go_left = n.key > key
                n = n.left if go_left else n.right
                if n is None:
                    if go_left:
                        parent.left = Node(key, parent)
                    else:
                        parent.right = Node(key, parent)
                    self.rebalance(parent)
                    break

    def delete(self, del_key):
        if self.root is None:
            return
        node = self.root
        child = self.root
        while child is not None:
            node = child
            child = del_key >= node.key and node.right or node.left
            if del_key == node.key:
                self.delete_node(node)
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
            return
        child = node.left if node.left is not None else node.right
        while child.right is not None:
            child = child.right
        node.key = child.key
        self.delete_node(child)

    def search(self, key):
        result = self.search_helper(self.root, key)
        return result is not None

    def search_helper(self, root, key):
        if root is None or root.key == key:
            return root
        return key < root.key and self.search_helper(root.left, key) or self.search_helper(root.right, key)

    def display(self):
        self.display_helper(self.root)
        print()

    def display_helper(self, node):
        if node is not None:
            self.display_helper(node.left)
            print(node.key, end=" ")
            self.display_helper(node.right)

    def rebalance(self, n):
        self.set_balance(n)
        if n.balance == -2:
            if self.height(n.left.left) >= self.height(n.left.right):
                n = self.rotate_right(n)
            else:
                n = self.rotate_left_then_right(n)
        elif n.balance == 2:
            if self.height(n.right.right) >= self.height(n.right.left):
                n = self.rotate_left(n)
            else:
                n = self.rotate_right_then_left(n)
        if n.parent is not None:
            self.rebalance(n.parent)
        else:
            self.root = n

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

    def height(self, n):
        return n.height if n is not None else -1

    def set_balance(self, *nodes):
        for n in nodes:
            self.reheight(n)
            n.balance = self.height(n.right) - self.height(n.left)

    def reheight(self, node):
        if node is not None:
            node.height = 1 + max(self.height(node.left), self.height(node.right))

    def main():
        tree = AVLTree()
        while True:
            command = input("Enter commands (insert <value>, delete <value>, search <value>, display, exit):").strip()
            if command.lower() == "exit":
                break
            parts = command.split(" ")
            try:
                if parts[0].lower() == "insert":
                    value_to_insert = int(parts[1])
                    tree.insert(value_to_insert)
                    print("Inserted:", value_to_insert)
                elif parts[0].lower() == "delete":
                    value_to_delete = int(parts[1])
                    tree.delete(value_to_delete)
                    print("Deleted:", value_to_delete)
                elif parts[0].lower() == "search":
                    value_to_search = int(parts[1])
                    print("Found" if tree.search(value_to_search) else "Not Found")
                elif parts[0].lower() == "display":
                    tree.display()
                else:
                    print("Unknown command")
            except Exception as e:
                print("Invalid command or input")

    if __name__ == "__main__":
        main()

