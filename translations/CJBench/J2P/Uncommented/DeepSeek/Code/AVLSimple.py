class Node:
    def __init__(self, data):
        self.data = data
        self.height = 1
        self.left = None
        self.right = None

class AVLTree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        self.root = self._insert(self.root, data)

    def _insert(self, node, item):
        if node is None:
            return Node(item)
        if node.data > item:
            node.left = self._insert(node.left, item)
        elif node.data < item:
            node.right = self._insert(node.right, item)
        node.height = max(self._height(node.left), self._height(node.right)) + 1
        bf = self._bf(node)
        if bf > 1 and item < node.left.data:
            return self._right_rotate(node)
        if bf < -1 and item > node.right.data:
            return self._left_rotate(node)
        if bf < -1 and item < node.right.data:
            node.right = self._right_rotate(node.right)
            return self._left_rotate(node)
        if bf > 1 and item > node.left.data:
            node.left = self._left_rotate(node.left)
            return self._right_rotate(node)
        return node

    def display(self):
        self._display(self.root)
        print("Tree Height:", self.root.height)

    def _display(self, node):
        if node is None:
            return
        str_repr = ""
        if node.left is not None:
            str_repr += str(node.left.data) + " => "
        else:
            str_repr += "END => "
        str_repr += str(node.data)
        if node.right is not None:
            str_repr += " <= " + str(node.right.data)
        else:
            str_repr += " <= END"
        print(str_repr)
        if node.left is not None:
            self._display(node.left)
        if node.right is not None:
            self._display(node.right)

    def _height(self, node):
        if node is None:
            return 0
        return node.height

    def _bf(self, node):
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
        command = input("Enter commands (insert <value>, display, exit):").strip()
        if command.lower() == "exit":
            break
        parts = command.split()
        try:
            if parts[0].lower() == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert")
                else:
                    value = int(parts[1])
                    tree.insert(value)
                    print("Inserted:", value)
            elif parts[0].lower() == "display":
                tree.display()
            else:
                print("Unknown command:", parts[0])
        except Exception as e:
            print("Error:", e)

if __name__ == "__main__":
    main()
