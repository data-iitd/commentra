class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class QItem:
    def __init__(self, node, hd):
        self.node = node
        self.hd = hd

class Tree:
    def __init__(self, root):
        self.root = root

    def print_top_view(self):
        if self.root is None:
            return

        set_hd = set()
        queue = []

        queue.append(QItem(self.root, 0))

        while queue:
            qi = queue.pop(0)
            hd = qi.hd
            n = qi.node

            if hd not in set_hd:
                set_hd.add(hd)
                print(n.key, end=" ")

            if n.left is not None:
                queue.append(QItem(n.left, hd - 1))

            if n.right is not None:
                queue.append(QItem(n.right, hd + 1))

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    n = int(data[0])
    node_map = {}

    for i in range(1, n + 1):
        key, left, right = map(int, data[i].split())
        if key not in node_map:
            node_map[key] = TreeNode(key)
        current_node = node_map[key]

        if left != -1:
            if left not in node_map:
                node_map[left] = TreeNode(left)
            current_node.left = node_map[left]

        if right != -1:
            if right not in node_map:
                node_map[right] = TreeNode(right)
            current_node.right = node_map[right]

    root_key = int(data[n + 1])
    t = Tree(node_map[root_key])
    t.print_top_view()

# <END-OF-CODE>
