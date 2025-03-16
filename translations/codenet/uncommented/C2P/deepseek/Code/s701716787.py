class TreeNode:
    def __init__(self, key):
        self.parent = None
        self.left = None
        self.right = None
        self.key = key

def d_insert(root, key):
    insert_node = TreeNode(key)
    parent_node = None
    current_node = root

    while current_node is not None:
        parent_node = current_node
        if insert_node.key < current_node.key:
            current_node = current_node.left
        else:
            current_node = current_node.right

    insert_node.parent = parent_node

    if parent_node is None:
        root = insert_node
    elif insert_node.key < parent_node.key:
        parent_node.left = insert_node
    else:
        parent_node.right = insert_node

def d_print(root):
    s_print_in_order(root)
    print()
    s_print_pre_order(root)
    print()

def s_print_pre_order(node):
    if node is None:
        return

    print(node.key, end=' ')
    s_print_pre_order(node.left)
    s_print_pre_order(node.right)

def s_print_in_order(node):
    if node is None:
        return

    s_print_in_order(node.left)
    print(node.key, end=' ')
    s_print_in_order(node.right)

def new_tree_node(key):
    return TreeNode(key)

def main():
    root = None
    num_commands = int(input())

    for _ in range(num_commands):
        command = input().strip()

        if command == "insert":
            key = int(input())
            d_insert(root, key)
        else:
            d_print(root)

if __name__ == "__main__":
    main()
