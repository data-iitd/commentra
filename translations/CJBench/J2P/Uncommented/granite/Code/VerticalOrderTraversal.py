

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
    max = 0
    min = 0
    queue.append(root)
    index.append(0)
    while queue:
        node = queue.pop(0)
        idx = index.pop(0)
        map[idx] = map.get(idx, []) + [node.data]
        max = max(max, idx)
        min = min(min, idx)
        if node.left is not None:
            queue.append(node.left)
            index.append(idx - 1)
        if node.right is not None:
            queue.append(node.right)
            index.append(idx + 1)
    result = []
    for i in range(min, max + 1):
        result.extend(map.get(i, []))
    return result

if __name__ == "__main__":
    n = int(input())
    nodes = [BinaryTree.Node(i) for i in range(1, n + 1)]
    for i in range(n - 1):
        parent, child, direction = map(str, input().split())
        parent = int(parent)
        child = int(child)
        if direction == "L":
            nodes[parent - 1].left = nodes[child - 1]
        else:
            nodes[parent - 1].right = nodes[child - 1]
    result = verticalTraversal(nodes[0])
    print(" ".join(map(str, result)))

