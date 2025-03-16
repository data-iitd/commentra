
import sys
from collections import defaultdict

class BinaryTree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

def verticalTraversal(root):
    if root is None:
        return []
    queue = []
    index = []
    map = defaultdict(list)
    max_idx = 0
    min_idx = 0
    queue.append(root)
    index.append(0)
    while queue:
        node = queue.pop(0)
        idx = index.pop(0)
        map[idx].append(node.data)
        max_idx = max(max_idx, idx)
        min_idx = min(min_idx, idx)
        if node.left:
            queue.append(node.left)
            index.append(idx - 1)
        if node.right:
            queue.append(node.right)
            index.append(idx + 1)
    result = []
    for i in range(min_idx, max_idx + 1):
        result.extend(map[i])
    return result

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    nodes = [None] + [BinaryTree.Node(i) for i in range(1, n + 1)]
    for i in range(1, n):
        parent, child = map(int, sys.stdin.readline().strip().split())
        direction = sys.stdin.readline().strip()
        if direction == "L":
            nodes[parent].left = nodes[child]
        else:
            nodes[parent].right = nodes[child]
    result = verticalTraversal(nodes[1])
    print(" ".join(map(str, result)))

