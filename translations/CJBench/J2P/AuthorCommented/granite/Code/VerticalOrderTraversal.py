

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def verticalTraversal(root):
    if root is None:
        return []

    queue = [root]
    index = [0]
    map = {}
    max_index = 0
    min_index = 0

    while queue:
        node = queue.pop(0)
        idx = index.pop(0)

        if idx not in map:
            map[idx] = []
        map[idx].append(node.data)

        max_index = max(max_index, idx)
        min_index = min(min_index, idx)

        if node.left:
            queue.append(node.left)
            index.append(idx - 1)
        if node.right:
            queue.append(node.right)
            index.append(idx + 1)

    result = []
    for i in range(min_index, max_index + 1):
        result.extend(map[i])

    return result

if __name__ == "__main__":
    n = int(input())
    nodes = [Node(i) for i in range(1, n + 1)]

    for _ in range(n - 1):
        parent, child, direction = input().split()
        parent = int(parent)
        child = int(child)

        if direction == "L":
            nodes[parent - 1].left = nodes[child - 1]
        else:
            nodes[parent - 1].right = nodes[child - 1]

    result = verticalTraversal(nodes[0])
    print(" ".join(map(str, result)))

