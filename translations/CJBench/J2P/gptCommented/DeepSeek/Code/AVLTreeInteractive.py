class Node:
    def __init__(self, key, parent=None):
        self.key = key
        self.balance = 0
        self.height = 0
        self.left = None
        self.right = None
        self.parent = parent


class AVLTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key, None)
        else:
            n = self.root
            parent = None
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
                    self._rebalance(parent)
                    break
        return True

    def delete(self, del_key):
        if self.root is None:
            return
        node = self.root
        child = self.root
        while child is not None:
            node = child
            child = del_key >= node.key and node.right or node.left
            if node.key == del_key:
                self._delete_node(node)
                return

    def _delete_node(self, node):
        if node.left is None and node.right is None:
            if node.parent is None:
                self.root = None
            else:
                parent = node.parent
                if parent.left == node:
                    parent.left = None
                else:
                    parent.right = None
                self._rebalance(parent)
        elif node.left is None:
            if node.parent is None:
                self.root = node.right
                self.root.parent = None
            else:
                parent = node.parent
                if parent.left == node:
                    parent.left = node.right
                else:
                    parent.right = node.right
                node.right.parent = parent
                self._rebalance(parent)
        elif node.right is None:
            if node.parent is None:
                self.root = node.left
                self.root.parent = None
            else:
                parent = node.parent
                if parent.left == node:
                    parent.left = node.left
                else:
                    parent.right = node.left
                node.left.parent = parent
                self._rebalance(parent)
        else:
            child = node.left
            while child.right is not None:
                child = child.right
            node.key = child.key
            self._delete_node(child)

    def search(self, key):
        result = self._search_helper(self.root, key)
        return result is not None

    def _search_helper(self, root, key):
        if root is None or root.key == key:
            return root
        return self._search_helper(root.left if key < root.key else root.right, key)

    def display(self):
        self._display_helper(self.root)
        print()

    def _display_helper(self, node):
        if node is not None:
            self._display_helper(node.left)
            print(node.key, end=" ")
            self._display_helper(node.right)

    def _rebalance(self, n):
        self._set_balance(n)
        while n is not None:
            parent = n.parent
            if n.balance == -2:
                if self.height(n.left.left) >= self.height(n.left.right):
                    n = self._rotate_right(n)
                else:
                    n = self._rotate_left_then_right(n)
            elif n.balance == 2:
                if self.height(n.right.right) >= self.height(n.right.left):
                    n = self._rotate_left(n)
                else:
                    n = self._rotate_right_then_left(n)
            if parent is not None:
                if parent.left == n:
                    parent.left = n
                else:
                    parent.right = n
            else:
                self.root = n
            n = parent

    def _rotate_left(self, a):
        b = a.right
        b.parent = a.parent
        a.right = b.left
        if a.right is not None:
            a.right.parent = a
        b.left = a
        a.parent = b
        self._set_balance(a, b)
        return b

    def _rotate_right(self, a):
        b = a.left
        b.parent = a.parent
        a.left = b.right
        if a.left is not None:
            a.left.parent = a
        b.right = a
        a.parent = b
        self._set_balance(a, b)
        return b

    def _rotate_left_then_right(self, n):
        n.left = self._rotate_left(n.left)
        return self._rotate_right(n)

    def _rotate_right_then_left(self, n):
        n.right = self._rotate_right(n.right)
        return self._rotate_left(n)

    def height(self, n):
        return -1 if n is None else n.height

    def _set_balance(self, *nodes):
        for n in nodes:
            self._reheight(n)
            n.balance = self.height(n.right) - self.height(n.left)

    def _reheight(self, node):
        if node is not None:
            node.height = 1 + max(self.height(node.left), self.height(node.right))


if __name__ == "__main__":
    tree = AVLTree()
    while True:
        command = input().strip()
        if command.lower() == "exit":
            break
        parts = command.split()
        try:
            if parts[0].lower() == "insert":
                value_to_insert = int(parts[1])
                inserted = tree.insert(value_to_insert)
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
