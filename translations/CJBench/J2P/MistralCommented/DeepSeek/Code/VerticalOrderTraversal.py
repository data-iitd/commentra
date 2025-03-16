from collections import defaultdict, deque

class BinaryTree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

def verticalTraversal(root):
    if root is None:
        return []

    queue = deque()
    index_queue = deque()
    map_ = defaultdict(list)
    min_idx, max_idx = 0, 0

    queue.append(root)
    index_queue.append(0)

    while queue:
        node = queue.popleft()
        idx = index_queue.popleft()

        map_[idx].append(node.data)
        min_idx = min(min_idx, idx)
        max_idx = max(max_idx, idx)

        if node.left:
            queue.append(node.left)
            index_queue.append(idx - 1)
        if node.right:
            queue.append(node.right)
            index_queue.append(idx + 1)

    result = []
    for i in range(min_idx, max_idx + 1):
        result.extend(map_[i])

    return result

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    nodes = [BinaryTree.Node(i) for i in range(n + 1)]

    i = 1
    for j in range(1, n - 1 + 1):
        parent = int(data[i])
        child = int(data[i + 1])
        direction = data[i + 2]
        i += 3

        if direction == "L":
            nodes[parent].left = nodes[child]
        elif direction == "R":
            nodes[parent].right = nodes[child]

    result = verticalTraversal(nodes[1])
    print(" ".join(map(str, result)))

if __name__ == "__main__":
    main()
