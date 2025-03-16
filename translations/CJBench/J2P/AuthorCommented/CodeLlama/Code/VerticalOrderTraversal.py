

import sys


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
    map = {}

    min = 0
    max = 0
    queue.append(root)
    index.append(0)

    while queue:
        node = queue.pop(0)
        idx = index.pop(0)

        map[idx] = map.get(idx, []) + [node.data]

        max = max(max, idx)
        min = min(min, idx)

        if node.left:
            queue.append(node.left)
            index.append(idx - 1)

        if node.right:
            queue.append(node.right)
            index.append(idx + 1)

    result = []
    for i in range(min, max + 1):
        result.extend(map.get(i, []))

    return result


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    nodes = [None] + [BinaryTree.Node(i) for i in range(1, n + 1)]
    for i in range(1, n):
        parent, child = map(int, sys.stdin.readline().split())
        if parent > child:
            nodes[parent].left = nodes[child]
        else:
            nodes[parent].right = nodes[child]

    result = verticalTraversal(nodes[1])
    print(*result, sep=" ")


