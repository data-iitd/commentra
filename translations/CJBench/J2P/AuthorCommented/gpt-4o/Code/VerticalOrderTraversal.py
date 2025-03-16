from collections import deque, defaultdict

class BinaryTree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

def vertical_traversal(root):
    if root is None:
        return []

    queue = deque()
    index = deque()
    map = defaultdict(list)

    max_idx = 0
    min_idx = 0
    queue.append(root)
    index.append(0)

    while queue:
        node = queue.popleft()
        idx = index.popleft()

        map[idx].append(node.data)

        max_idx = max(max_idx, idx)
        min_idx = min(min_idx, idx)

        if node.left is not None:
            queue.append(node.left)
            index.append(idx - 1)
        if node.right is not None:
            queue.append(node.right)
            index.append(idx + 1)

    result = []
    for i in range(min_idx, max_idx + 1):
        result.extend(map[i])

    return result

if __name__ == "__main__":
    n = int(input())
    nodes = [None] * (n + 1)
    for i in range(1, n + 1):
        nodes[i] = BinaryTree.Node(i)

    for _ in range(n - 1):
        parent, child, direction = input().split()
        parent = int(parent)
        child = int(child)

        if direction == "L":
            nodes[parent].left = nodes[child]
        elif direction == "R":
            nodes[parent].right = nodes[child]

    result = vertical_traversal(nodes[1])

    print(" ".join(map(str, result)))

# <END-OF-CODE>
