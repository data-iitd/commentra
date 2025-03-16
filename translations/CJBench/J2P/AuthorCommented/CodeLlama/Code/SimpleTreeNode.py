
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def pre_order_traversal(root):
    if root is None:
        return

    print(root.data, end=" ")
    pre_order_traversal(root.left)
    pre_order_traversal(root.right)

# Input number of nodes
n = int(input())

# Create an array of nodes
nodes = [None] * (n + 1)
for i in range(1, n + 1):
    nodes[i] = Node(i)

# Input edges
for i in range(n - 1):
    parent, child = map(int, input().split())
    direction = input()

    if direction == "L":
        nodes[parent].left = nodes[child]
    else:
        nodes[parent].right = nodes[child]

# Perform pre-order traversal and print the tree
pre_order_traversal(nodes[1])

# 