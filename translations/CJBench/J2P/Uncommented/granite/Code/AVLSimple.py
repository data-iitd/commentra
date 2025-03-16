
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
        elif node.data < data:
            node.right = self.insert_node(node.right, data)
        node.height = max(self.height(node.left), self.height(node.right)) + 1
        bf = self.get_balance_factor(node)
        if bf > 1 and data < node.left.data:
            return self.right_rotate(node)
        if bf < -1 and data > node.right.data:
            return self.left_rotate(node)
        if bf < -1 and data < node.right.data:
            node.right = self.right_rotate(node.right)
            return self.left_rotate(node)
        if bf > 1 and data > node.left.data:
            node.left = self.left_rotate(node.left)
            return self.right_rotate(node)
        return node

    def display(self):
        self.display_node(self.root)
        print("Tree Height: ", self.root.height)

    def display_node(self, node):
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
            self.display_node(node.left)
        if node.right is not None:
            self.display_node(node.right)

    def height(self, node):
        if node is None:
            return 0
        return node.height

    def get_balance_factor(self, node):
        if node is None:
            return 0
        return self.height(node.left) - self.height(node.right)

    def right_rotate(self, c):
        b = c.left
        t3 = b.right
        b.right = c
        c.left = t3
        c.height = max(self.height(c.left), self.height(c.right)) + 1
        b.height = max(self.height(b.left), self.height(b.right)) + 1
        return b

    def left_rotate(self, c):
        b = c.right
        t3 = b.left
        b.left = c
        c.right = t3
        c.height = max(self.height(c.left), self.height(c.right)) + 1
        b.height = max(self.height(b.left), self.height(b.right)) + 1
        return b

if __name__ == "__main__":
    tree = AVLTree()
    while True:
        command = input("Enter command (insert <value>, display, exit): ")
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
                    print("Inserted: ", value)
            elif parts[0].lower() == "display":
                tree.display()
            else:
                print("Unknown command: ", parts[0])
        except Exception as e:
            print("Error: ", e)

