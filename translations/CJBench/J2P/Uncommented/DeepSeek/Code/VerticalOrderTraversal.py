class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def verticalTraversal(root):
    if root is None:
        return []
    queue = [(root, 0)]
    index_map = {}
    min_idx = max_idx = 0
    while queue:
        node, idx = queue.pop(0)
        if idx not in index_map:
            index_map[idx] = []
        index_map[idx].append(node.data)
        if node.left:
            queue.append((node.left, idx - 1))
        if node.right:
            queue.append((node.right, idx + 1))
        min_idx = min(min_idx, idx)
        max_idx = max(max_idx, idx)
    result = []
    for i in range(min_idx, max_idx + 1):
        result.extend(index_map[i])
    return result

# Main function to take input and print output
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    nodes = [Node(i) for i in range(n + 1)]
    idx = 1
    for i in range(1, n):
        parent = int(data[idx])
        child = int(data[idx + 1])
        direction = data[idx + 2]
        idx += 3
        if direction == "L":
            nodes[parent].left = nodes[child]
        elif direction == "R":
            nodes[parent].right = nodes[child]
    result = verticalTraversal(nodes[1])
    print(" ".join(map(str, result)))

if __name__ == "__main__":
    main()
