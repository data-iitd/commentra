
import sys

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def preOrderTraversal(root):
    if root is None:
        return
    print(root.data, end=" ")
    preOrderTraversal(root.left)
    preOrderTraversal(root.right)

n = int(input())
nodes = [None] * (n + 1)

for i in range(1, n + 1):
    nodes[i] = Node(i)

for i in range(n - 1):
    parent, child = map(int, input().split())
    direction = input()
    if direction == "L":
        nodes[parent].left = nodes[child]
    else:
        nodes[parent].right = nodes[child]

preOrderTraversal(nodes[1])

# 