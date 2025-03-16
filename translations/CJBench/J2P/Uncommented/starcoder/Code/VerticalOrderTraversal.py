
import collections
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
    queue = collections.deque()
    queue.append((root, 0))
    index = collections.deque()
    index.append(0)
    result = collections.defaultdict(list)
    max_index = 0
    min_index = 0
    while queue:
        node, idx = queue.popleft()
        max_index = max(max_index, idx)
        min_index = min(min_index, idx)
        result[idx].append(node.data)
        if node.left:
            queue.append((node.left, idx - 1))
            index.append(idx - 1)
        if node.right:
            queue.append((node.right, idx + 1))
            index.append(idx + 1)
    result_list = []
    for i in range(min_index, max_index + 1):
        result_list.extend(result[i])
    return result_list

def main():
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("output.txt", "w")
    n = int(input())
    nodes = [BinaryTree.Node(i) for i in range(1, n + 1)]
    for i in range(n - 1):
        parent, child, direction = map(int, input().split())
        if direction == 0:
            nodes[parent].left = nodes[child]
        else:
            nodes[parent].right = nodes[child]
    result = verticalTraversal(nodes[1])
    for value in result:
        print(value, end=" ")

if __name__ == "__main__":
    main()

