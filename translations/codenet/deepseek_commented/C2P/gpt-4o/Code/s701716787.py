class STNode:
    def __init__(self, key):
        self.parent = None
        self.left = None
        self.right = None
        self.key = key

def insert(root, key):
    new_node = STNode(key)
    parent_node = None
    index_node = root

    while index_node is not None:
        parent_node = index_node
        if new_node.key < index_node.key:
            index_node = index_node.left
        else:
            index_node = index_node.right

    new_node.parent = parent_node

    if parent_node is None:
        return new_node  # The tree was empty, new node becomes the root
    elif key < parent_node.key:
        parent_node.left = new_node
    else:
        parent_node.right = new_node

    return root

def print_tree(root):
    print_in_order(root)
    print()  # New line
    print_pre_order(root)
    print()  # New line

def print_pre_order(node):
    if node is None:
        return
    print(f" {node.key}", end="")
    print_pre_order(node.left)
    print_pre_order(node.right)

def print_in_order(node):
    if node is None:
        return
    print_in_order(node.left)
    print(f" {node.key}", end="")
    print_in_order(node.right)

def main():
    root = None
    num_commands = int(input())

    for _ in range(num_commands):
        command = input().strip()
        if command == "insert":
            key = int(input())
            root = insert(root, key)
        else:  # Assuming the command is "print"
            print_tree(root)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
