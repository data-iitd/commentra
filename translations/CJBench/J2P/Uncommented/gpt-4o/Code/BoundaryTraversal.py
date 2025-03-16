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

def add_left_boundary(node, result):
    cur = node.left
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
    result.extend(reversed(temp))

def is_leaf(node):
    return node.left is None and node.right is None

def build_tree():
    n = int(input("Enter the number of nodes and edges: "))
    map = {}
    root = None
    for _ in range(n):
        parent, direction, child = input().split()
        parent = int(parent)
        child = int(child)
        parent_node = map.get(parent, Node(parent))
        child_node = Node(child)
        if direction == "L":
            parent_node.left = child_node
        elif direction == "R":
            parent_node.right = child_node
        map[parent] = parent_node
        map[child] = child_node
        if root is None:
            root = parent_node
    return root

if __name__ == "__main__":
    root = build_tree()
    print("Boundary traversal:")
    result = boundary_traversal(root)
    print(" ".join(map(str, result)))

# <END-OF-CODE>
