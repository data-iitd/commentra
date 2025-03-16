
import sys
from collections import defaultdict

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

    max = 0
    min = 0
    queue.append(root)
    index.append(0)

    while queue:
        node = queue.pop(0)
        idx = index.pop(0)

        map[idx].append(node.data)

        max = max if max > idx else idx
        min = min if min < idx else idx

        if node.left:
            queue.append(node.left)
            index.append(idx - 1)
        if node.right:
            queue.append(node.right)
            index.append(idx + 1)

    result = []
    for i in range(min, max + 1):
        result.extend(map[i])

    return result

if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

    n = int(input())
    nodes = [Node(i) for i in range(1, n + 1)]

    for i in range(n - 1):
        parent, child, direction = map(int, input().split())
        if direction == 'L':
            nodes[parent - 1].left = nodes[child - 1]
        else:
            nodes[parent - 1].right = nodes[child - 1]

    result = verticalTraversal(nodes[0])

    for value in result:
        print(value, end=' ')

    sys.stdout.close()

