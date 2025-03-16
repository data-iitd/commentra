class AVLTree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.height = 1
            self.left = None
            self.right = None

    def __init__(self):
        self.root = None

    def insert(self, data):
        self.root = self._insert(self.root, data)

    def _insert(self, node, item):
        if node is None:
            return self.Node(item)

        if item < node.data:
            node.left = self._insert(node.left, item)
        elif item > node.data:
            node.right = self._insert(node.right, item)

        node.height = max(self._height(node.left), self._height(node.right)) + 1

        bf = self._balance_factor(node)
        if bf > 1:
            if item < node.left.data:
                return self._right_rotate(node)
            node.left = self._left_rotate(node.left)
            return self._right_rotate(node)
        elif bf < -1:
            if item > node.right.data:
                return self._left_rotate(node)
            node.right = self._right_rotate(node.right)
            return self._left_rotate(node)

        return node

    def display(self):
        self._display(self.root)
        print("Tree Height:", self.root.height if self.root else 0)

    def _display(self, node):
        if node is None:
            return

        str_repr = ""
        if node.left is not None:
            str_repr += f"{node.left.data} => "
        else:
            str_repr += "END => "

        str_repr += str(node.data)

        if node.right is not None:
            str_repr += f" <= {node.right.data}"
        else:
            str_repr += " <= END"

        print(str_repr)

        self._display(node.left)
        self._display(node.right)

    def _height(self, node):
        if node is None:
            return 0
        return node.height

    def _balance_factor(self, node):
        if node is None:
            return 0
        return self._height(node.left) - self._height(node.right)

    def _right_rotate(self, c):
        b = c.left
        t3 = b.right

        b.right = c
        c.left = t3

        c.height = max(self._height(c.left), self._height(c.right)) + 1
        b.height = max(self._height(b.left), self._height(b.right)) + 1

        return b

    def _left_rotate(self, c):
        b = c.right
        t3 = b.left

        b.left = c
        c.right = t3

        c.height = max(self._height(c.left), self._height(c.right)) + 1
        b.height = max(self._height(b.left), self._height(b.right)) + 1

        return b


def main():
    tree = AVLTree()
    while True:
        command = input().strip()
        if command.lower() == "exit":
            break

        parts = command.split()
        try:
            if parts[0] == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert")
                else:
                    value = int(parts[1])
                    tree.insert(value)
                    print(f"Inserted: {value}")
            elif parts[0] == "display":
                tree.display()
            else:
                print(f"Unknown command: {parts[0]}")
        except Exception as e:
            print(f"Error: {e}")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
