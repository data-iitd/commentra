
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

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

def is_leaf(node):
    return node.left is None and node.right is None

def add_left_boundary(node, result):
    cur = node.left
    temp = []

    while cur is not None:
        if not is_leaf(cur):
            result.append(cur.data)

        cur = cur.left if cur.left is not None else cur.right

def add_leaves(node, result):
    if node is None:
        return

    if is_leaf(node):
        result.append(node.data)
    else:
        add_leaves(node.left, result)
        add_leaves(node.right, result)

def add_right_boundary(node, result):
    cur = node.right
    temp = []

    while cur is not None:
        if not is_leaf(cur):
            temp.append(cur.data)

        cur = cur.right if cur.right is not None else cur.left

    while len(temp) > 0:
        result.append(temp.pop())

def build_tree(scanner):
    n = scanner.nextInt()
    map = {}
    root = None

    for i in range(n):
        parent = scanner.nextInt()
        direction = scanner.next()
        child = scanner.nextInt()

        child_node = Node(child)

        if root is None:
            root = parent

        parent_node = map.get(parent, Node(parent))
        if direction == "L":
            parent_node.left = child_node
        else:
            parent_node.right = child_node

        map[parent] = parent_node
        map[child] = child_node

    return root

def main():
    scanner = Scanner(System.in)

    root = build_tree(scanner)

    result = boundary_traversal(root)

    print("Boundary traversal:")
    for value in result:
        print(value, end=" ")
    print()

    scanner.close()

if __name__ == "__main__":
    main()

