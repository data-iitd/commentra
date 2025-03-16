class Node:
    def __init__(self, key):
        self.key = key
        self.color = 1  # 1 for black, 0 for red
        self.left = None
        self.right = None
        self.p = None


class RedBlackTree:
    def __init__(self):
        self.nil = Node(-1)
        self.nil.color = 1
        self.root = self.nil

    def print_tree(self, node):
        if node == self.nil:
            return
        self.print_tree(node.left)
        print("B" if node.color == 1 else "R", node.key, end=" ")
        self.print_tree(node.right)

    def insert(self, key):
        node = Node(key)
        node.parent = None
        node.left = self.nil
        node.right = self.nil
        node.color = 0  # New nodes are always red

        temp = self.root
        y = self.nil
        while temp != self.nil:
            y = temp
            if node.key < temp.key:
                temp = temp.left
            else:
                temp = temp.right
        node.parent = y
        if y == self.nil:
            self.root = node
        elif node.key < y.key:
            y.left = node
        else:
            y.right = node
        if node.parent == self.nil:
            node.color = 1
            return
        if node.parent.parent == self.nil:
            return
        self.fix_insert(node)

    def fix_insert(self, node):
        while node.parent.color == 0:
            if node.parent == node.parent.parent.right:
                y = node.parent.parent.left
                if y.color == 0:
                    y.color = 1
                    node.parent.color = 1
                    node.parent.parent.color = 0
                    node = node.parent.parent
                else:
                    if node == node.parent.left:
                        node = node.parent
                        self.right_rotate(node)
                    node.parent.color = 1
                    node.parent.parent.color = 0
                    self.left_rotate(node.parent.parent)
            else:
                y = node.parent.parent.right
                if y.color == 0:
                    y.color = 1
                    node.parent.color = 1
                    node.parent.parent.color = 0
                    node = node.parent.parent
                else:
                    if node == node.parent.right:
                        node = node.parent
                        self.left_rotate(node)
                    node.parent.color = 1
                    node.parent.parent.color = 0
                    self.right_rotate(node.parent.parent)
        self.root.color = 1

    def left_rotate(self, node):
        y = node.right
        node.right = y.left
        if y.left != self.nil:
            y.left.parent = node
        y.parent = node.parent
        if node.parent == self.nil:
            self.root = y
        elif node == node.parent.left:
            node.parent.left = y
        else:
            node.parent.right = y
        y.left = node
        node.parent = y

    def right_rotate(self, node):
        y = node.left
        node.left = y.right
        if y.right != self.nil:
            y.right.parent = node
        y.parent = node.parent
        if node.parent == self.nil:
            self.root = y
        elif node == node.parent.right:
            node.parent.right = y
        else:
            node.parent.left = y
        y.right = node
        node.parent = y

    def print_in_order(self):
        self.print_tree(self.root)
        print()


if __name__ == "__main__":
    rb_tree = RedBlackTree()
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    keys = list(map(int, data[1:]))
    for key in keys:
        rb_tree.insert(key)
    print("In-order traversal:")
    rb_tree.print_in_order()
