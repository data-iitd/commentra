class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def is_leaf(node):
    return node.left is None and node.right is None

def add_left_boundary(node, result):
    cur = node.left
    temp = []

    while cur:
        if not is_leaf(cur):
            result.append(cur.data)
        cur = cur.left if cur.left else cur.right

def add_leaves(node, result):
    if node:
        if is_leaf(node):
            result.append(node.data)
        else:
            add_leaves(node.left, result)
            add_leaves(node.right, result)

def add_right_boundary(node, result):
    cur = node.right
    temp = []

    while cur:
        if not is_leaf(cur):
            temp.append(cur.data)
        cur = cur.right if cur.right else cur.left

    while temp:
        result.append(temp.pop())

def boundary_traversal(root):
    result = []

    if root is None:
        return result

    if not is_leaf(root):
        result.append(root.data)

    add_left_boundary(root, result)
    add_leaves(root, result)
    add_right_boundary(root, result)

    return result

def build_tree(scanner):
    n = int(scanner.readline().strip())
    map_ = {}
    root = None

    for _ in range(n):
        parent, direction, child = map(int, scanner.readline().strip().split())

        if root is None:
            root = parent

        child_node = Node(child)
        parent_node = map_.get(parent, Node(parent))
        if direction == 'L':
            parent_node.left = child_node
        elif direction == 'R':
            parent_node.right = child_node

        map_[parent] = parent_node
        map_[child] = child_node

    return root

def main():
    import sys
    scanner = sys.stdin

    root = build_tree(scanner)
    result = boundary_traversal(root)

    print("Boundary traversal:")
    print(" ".join(map(str, result)))

if __name__ == "__main__":
    main()
