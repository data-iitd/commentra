
import sys

COMMAND_LENGTH = 10

class ST_NODE:
    def __init__(self, key):
        self.parent = None
        self.left = None
        self.right = None
        self.key = key

def d_insert(root, key):
    parent = None
    index = root
    while index is not None:
        parent = index
        if key < index.key:
            index = index.left
        else:
            index = index.right
    node = ST_NODE(key)
    node.parent = parent
    if parent is None:
        root = node
    elif key < parent.key:
        parent.left = node
    else:
        parent.right = node

def d_print(root):
    s_printInOrder(root)
    print()
    s_printPreOrder(root)
    print()

def s_printPreOrder(node):
    if node is None:
        return
    print(" %d" % node.key, end="")
    s_printPreOrder(node.left)
    s_printPreOrder(node.right)

def s_printInOrder(node):
    global printedNumNode
    if node is None:
        return
    s_printInOrder(node.left)
    print(" %d" % node.key, end="")
    s_printInOrder(node.right)

def dp_newST_NODE(key):
    node = ST_NODE(key)
    node.parent = None
    node.left = None
    node.right = None
    return node

if __name__ == "__main__":
    root = None
    numCommand = int(input())
    for i in range(numCommand):
        command = input()
        if command == "insert":
            key = int(input())
            d_insert(root, key)
        else:
            d_print(root)

print("