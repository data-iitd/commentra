
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
        self.root = self.insert(self.root, data)

    def insert(self, node, item):
        if node is None:
            return Node(item)

        if node.data > item:
            node.left = self.insert(node.left, item)
        else:
            node.right = self.insert(node.right, item)

        node.height = max(self.height(node.left), self.height(node.right)) + 1

        bf = self.bf(node)
        if bf > 1:
            if item < node.left.data:
                return self.rightRotate(node)
            node.right = self.rightRotate(node.right)
            return self.leftRotate(node)
        elif bf < -1:
            if item > node.right.data:
                return self.leftRotate(node)
            node.left = self.leftRotate(node.left)
            return self.rightRotate(node)

        return node

    def height(self, node):
        if node is None:
            return 0
        return node.height

    def bf(self, node):
        if node is None:
            return 0
        return self.height(node.left) - self.height(node.right)

    def rightRotate(self, c):
        b = c.left
        t3 = b.right

        b.right = c
        c.left = t3

        c.height = max(self.height(c.left), self.height(c.right)) + 1
        b.height = max(self.height(b.left), self.height(b.right)) + 1

        return b

    def leftRotate(self, c):
        b = c.right
        t3 = b.left

        b.left = c
        c.right = t3

        c.height = max(self.height(c.left), self.height(c.right)) + 1
        b.height = max(self.height(b.left), self.height(b.right)) + 1

        return b

    def display(self):
        self.display(self.root)
        print("Tree Height: " + str(self.root.height))

    def display(self, node):
        if node is None:
            return

        str = ""
        if node.left is not None:
            str += str(node.left.data) + " => "
        else:
            str += "END => "

        str += str(node.data)

        if node.right is not None:
            str += " <= " + str(node.right.data)
        else:
            str += " <= END"

        print(str)

        if node.left is not None:
            self.display(node.left)
        if node.right is not None:
            self.display(node.right)


if __name__ == "__main__":
    tree = AVLTree()
    scanner = input("Enter a command: ")

    while scanner != "exit":
        parts = scanner.split(" ")

        try:
            if parts[0] == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert")
                else:
                    value = int(parts[1])
                    tree.insert(value)
                    print("Inserted: " + str(value))
            elif parts[0] == "display":
                tree.display()
            else:
                print("Unknown command: " + parts[0])
        except Exception as e:
            print("Error: " + str(e))

        scanner = input("Enter a command: ")

    print("