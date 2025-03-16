class Node:
    def __init__(self, key):
        self.key = key
        self.color = 'BLACK'
        self.left = None
        self.right = None
        self.p = None

nil = Node(-1)
nil.color = 'BLACK'

class RedBlackTree:
    def __init__(self):
        self.root = nil

    def print_tree(self, node):
        if node == nil:
            return
        self.print_tree(node.left)
        print((('R ' if node.color == 'RED' else 'B ') + str(node.key) + ' '), end='')
        self.print_tree(node.right)

    def insert(self, key):
        node = Node(key)
        temp = self.root
        if self.root == nil:
            self.root = node
            node.color = 'BLACK'
        else:
            node.color = 'RED'
            while True:
                if key < temp.key:
                    if temp.left == nil:
                        temp.left = node
                        node.p = temp
                        break
                    temp = temp.left
                else:
                    if temp.right == nil:
                        temp.right = node
                        node.p = temp
                        break
                    temp = temp.right
            self.fix_tree(node)

    def fix_tree(self, node):
        while node.p.color == 'RED':
            if node.p == node.p.p.left:
                y = node.p.p.right
                if y.color == 'RED':
                    node.p.color = 'BLACK'
                    y.color = 'BLACK'
                    node.p.p.color = 'RED'
                    node = node.p.p
                else:
                    if node == node.p.right:
                        node = node.p
                        self.rotate_left(node)
                    node.p.color = 'BLACK'
                    node.p.p.color = 'RED'
                    self.rotate_right(node.p.p)
            else:
                y = node.p.p.left
                if y.color == 'RED':
                    node.p.color = 'BLACK'
                    y.color = 'BLACK'
                    node.p.p.color = 'RED'
                    node = node.p.p
                else:
                    if node == node.p.left:
                        node = node.p
                        self.rotate_right(node)
                    node.p.color = 'BLACK'
                    node.p.p.color = 'RED'
                    self.rotate_left(node.p.p)
        self.root.color = 'BLACK'

    def rotate_left(self, node):
        temp = node.right
        node.right = temp.left
        if temp.left != nil:
            temp.left.p = node
        temp.p = node.p
        if node.p == nil:
            self.root = temp
        elif node == node.p.left:
            node.p.left = temp
        else:
            node.p.right = temp
        temp.left = node
        node.p = temp

    def rotate_right(self, node):
        temp = node.left
        node.left = temp.right
        if temp.right != nil:
            temp.right.p = node
        temp.p = node.p
        if node.p == nil:
            self.root = temp
        elif node == node.p.right:
            node.p.right = temp
        else:
            node.p.left = temp
        temp.right = node
        node.p = temp

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
