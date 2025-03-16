class Node:
    def __init__(self, data):
        self.data = data
        self.left_node = None
        self.right_node = None

    def is_leaf_node(self):
        return self.left_node is None and self.right_node is None


def pre_order_traversal(root):
    if root is None:
        return
    print(root.data, end=' ')
    pre_order_traversal(root.left_node)
    pre_order_traversal(root.right_node)


def main():
    n = int(input())
    nodes = [None] * (n + 1)
    for i in range(1, n + 1):
        nodes[i] = Node(i)

    for _ in range(n - 1):
        parent, child, direction = input().split()
        parent = int(parent)
        child = int(child)
        if direction == "L":
            nodes[parent].left_node = nodes[child]
        elif direction == "R":
            nodes[parent].right_node = nodes[child]

    pre_order_traversal(nodes[1])


if __name__ == "__main__":
    main()

# <END-OF-CODE>
