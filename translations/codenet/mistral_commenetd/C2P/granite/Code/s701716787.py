
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
    num_command = int(input("Enter the number of commands: "))
    for i in range(num_command):
        command = input("Enter the command (insert or print): ")
        if command == "insert":
            key = int(input("Enter the key to be inserted: "))
            d_insert(root, key)
        elif command == "print":
            d_print(root)
        else:
            print("Invalid command")
            sys.exit(1)

