
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

    def insert(self, node, data):
        if node is None:
            return Node(data)
        if node.data > data:
            node.left = self.insert(node.left, data)
        else:
            node.right = self.insert(node.right, data)
        node.height = max(self.height(node.left), self.height(node.right)) + 1
        bf = self.bf(node)
        # LL case
        if bf > 1 and data < node.left.data:
            return self.rightRotate(node)
        # RR case
        if bf < -1 and data > node.right.data:
            return self.leftRotate(node)
        # RL case
        if bf < -1 and data < node.right.data:
            node.right = self.rightRotate(node.right)
            return self.leftRotate(node)
        # LR case
        if bf > 1 and data > node.left.data:
            node.left = self.leftRotate(node.left)
            return self.rightRotate(node)

        return node

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

    def height(self, node):
        if node is None:
            return 0
        return node.height

    def bf(self, node):
        if node is None:
            return 0
        return self.height(node.left) - self.height(node.right)

    def rightRotate(self, node):
        b = node.left
        t3 = b.right

        b.right = node
        node.left = t3
        node.height = max(self.height(node.left), self.height(node.right)) + 1
        b.height = max(self.height(b.left), self.height(b.right)) + 1
        return b

    def leftRotate(self, node):
        b = node.right
        t3 = b.left

        b.left = node
        node.right = t3
        node.height = max(self.height(node.left), self.height(node.right)) + 1
        b.height = max(self.height(b.left), self.height(b.right)) + 1
        return b


if __name__ == "__main__":
    tree = AVLTree()
    tree.insert(20)
    tree.insert(25)
    tree.insert(30)
    tree.insert(10)
    tree.insert(5)
    tree.insert(15)
    tree.insert(27)
    tree.insert(19)
    tree.insert(16)

    tree.display()

