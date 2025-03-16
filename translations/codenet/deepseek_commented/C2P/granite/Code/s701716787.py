
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
    index_node = root
    while index_node is not None:
        parent = index_node
        if key < index_node.key:
            index_node = index_node.left
        else:
            index_node = index_node.right
    insert_node = ST_NODE(key)
    insert_node.parent = parent
    if parent is None:
        root = insert_node
    elif key < parent.key:
        parent.left = insert_node
    else:
        parent.right = insert_node

def d_print(root):
    s_printInOrder(root)
    print()
    s_printPreOrder(root)
    print()

def s_printPreOrder(node):
    if node is None:
        return
    print(f" {node.key}", end="")
    s_printPreOrder(node.left)
    s_printPreOrder(node.right)

def s_printInOrder(node):
    global printed_num_node
    if node is None:
        return
    s_printInOrder(node.left)
    print(f" {node.key}", end="")
    s_printInOrder(node.right)

def dp_newST_NODE(key):
    node = ST_NODE(key)
    node.parent = None
    node.left = None
    node.right = None
    return node

if __name__ == "__main__":
    root = None
    num_command = int(input())
    for i in range(num_command):
        command = input()
        if command == "insert":
            key = int(input())
            d_insert(root, key)
        else:
            d_print(root)

