
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
        self.root = self.insert_node(self.root, data)

    def insert_node(self, node, data):
        if node is None:
            return Node(data)
        if node.data > data:
            node.left = self.insert_node(node.left, data)
        else:
            node.right = self.insert_node(node.right, data)
        node.height = max(self.get_height(node.left), self.get_height(node.right)) + 1
        balance = self.get_balance(node)
        if balance > 1 and data < node.left.data:
            return self.right_rotate(node)
        if balance < -1 and data > node.right.data:
            return self.left_rotate(node)
        if balance > 1 and data > node.left.data:
            node.left = self.left_rotate(node.left)
            return self.right_rotate(node)
        if balance < -1 and data < node.right.data:
            node.right = self.right_rotate(node.right)
            return self.left_rotate(node)
        return node

    def get_height(self, node):
        if node is None:
            return 0
        return node.height

    def get_balance(self, node):
        if node is None:
            return 0
        return self.get_height(node.left) - self.get_height(node.right)

    def right_rotate(self, node):
        b = node.left
        t3 = b.right
        b.right = node
        node.left = t3
        node.height = max(self.get_height(node.left), self.get_height(node.right)) + 1
        b.height = max(self.get_height(b.left), self.get_height(b.right)) + 1
        return b

    def left_rotate(self, node):
        b = node.right
        t3 = b.left
        b.left = node
        node.right = t3
        node.height = max(self.get_height(node.left), self.get_height(node.right)) + 1
        b.height = max(self.get_height(b.left), self.get_height(b.right)) + 1
        return b

    def display(self):
        self.display_node(self.root)
        print("Tree Height: " + str(self.root.height))

    def display_node(self, node):
        if node is None:
            return
        if node.left is not None:
            print(node.left.data, "=>", end=" ")
        else:
            print("END => ", end=" ")
        print(node.data, end=" ")
        if node.right is not None:
            print("<= " + str(node.right.data))
        else:
            print("<= END")
        self.display_node(node.left)
        self.display_node(node.right)


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