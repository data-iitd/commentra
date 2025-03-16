class TreeNode:
    def __init__(self, key):
        self.key = key
        self.parent = None
        self.left = None
        self.right = None

def insert(root, key):
    new_node = TreeNode(key)
    parent_node = None
    current_node = root

    while current_node is not None:
        parent_node = current_node
        if new_node.key < current_node.key:
            current_node = current_node.left
        else:
            current_node = current_node.right

    new_node.parent = parent_node

    if parent_node is None:
        root = new_node
    elif new_node.key < parent_node.key:
        parent_node.left = new_node
    else:
        parent_node.right = new_node

def print_tree(root):
    def in_order_traversal(node):
        if node is not None:
            in_order_traversal(node.left)
            print(f" {node.key}", end='')
            in_order_traversal(node.right)

    def pre_order_traversal(node):
        if node is not None:
            print(f" {node.key}", end='')
            pre_order_traversal(node.left)
            pre_order_traversal(node.right)

    print("In-order traversal:", end='')
    in_order_traversal(root)
    print()
    print("Pre-order traversal:", end='')
    pre_order_traversal(root)
    print()

def main():
    root = None
    num_commands = int(input())

    for _ in range(num_commands):
        command = input().strip()

        if command == "insert":
            key = int(input())
            insert(root, key)
        elif command == "print":
            print_tree(root)

if __name__ == "__main__":
    main()
