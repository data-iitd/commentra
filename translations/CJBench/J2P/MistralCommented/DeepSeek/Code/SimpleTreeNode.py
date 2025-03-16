class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left_node = None
        self.right_node = None

    def get_data(self):
        return self.data

    def set_left_node(self, left_node):
        self.left_node = left_node

    def set_right_node(self, right_node):
        self.right_node = right_node

    def get_left_node(self):
        return self.left_node

    def get_right_node(self):
        return self.right_node

    def is_leaf_node(self):
        return self.left_node is None and self.right_node is None


def pre_order_traversal(root):
    if root is None:
        return

    print(root.get_data(), end=' ')
    pre_order_traversal(root.get_left_node())
    pre_order_traversal(root.get_right_node())


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    nodes = [TreeNode(i) for i in range(n + 1)]

    index = 1
    for i in range(1, n + 1):
        parent = int(data[index])
        child = int(data[index + 1])
        direction = data[index + 2]
        index += 3

        if direction == 'L':
            nodes[parent].set_left_node(nodes[child])
        elif direction == 'R':
            nodes[parent].set_right_node(nodes[child])

    pre_order_traversal(nodes[1])


if __name__ == "__main__":
    main()
