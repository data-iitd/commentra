from collections import deque, defaultdict

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

    min_idx = max_idx = 0
    queue.append(root)
    index_queue.append(0)

    while queue:
        node = queue.popleft()
        idx = index_queue.popleft()

        map_[idx].append(node.data)

        if idx < min_idx:
            min_idx = idx
        if idx > max_idx:
            max_idx = idx

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

# Example usage:
# Construct the binary tree from the input
# ...
# result = verticalTraversal(root)
# print(*result)

