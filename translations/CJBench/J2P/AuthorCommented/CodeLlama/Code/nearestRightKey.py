
import sys

class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def build_tree(n):
    node_map = {}
    root = None

    for i in range(n):
        value = int(sys.stdin.readline().strip())
        left = int(sys.stdin.readline().strip())
        right = int(sys.stdin.readline().strip())

        node_map[value] = Node(value)
        current = node_map[value]

        if root is None:
            root = current

        if left != -1:
            node_map[left] = Node(left)
            current.left = node_map[left]

        if right != -1:
            node_map[right] = Node(right)
            current.right = node_map[right]

    return root

def find_nearest_right_key(root, x0):
    if root is None:
        return 0
    elif root.value > x0:
        temp = find_nearest_right_key(root.left, x0)
        if temp == 0:
            return root.value
        return temp
    else:
        return find_nearest_right_key(root.right, x0)

n = int(sys.stdin.readline().strip())
root = build_tree(n)
x0 = int(sys.stdin.readline().strip())

to_print = find_nearest_right_key(root, x0)
if to_print == 0:
    print("No nearest right key found.")
else:
    print("Nearest Right Key:", to_print)

# 