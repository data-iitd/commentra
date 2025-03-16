
import sys

class Node:
    def __init__(self, index):
        self.index = index
        self.pattern = 0
        self.parent = -1
        self.children = []

def set_parent(node, K, parent, use, nodes):
    node.pattern = K - use
    node.parent = parent
    count = 1
    if parent!= -1:
        count += 1
    for child in node.children:
        if child == node.parent:
            continue
        nodes[child].setParent(K, node.index, count, nodes)
        count += 1

def solve():
    N, K = map(int, input().split())
    nodes = [Node(i) for i in range(N)]
    for _ in range(N - 1):
        a, b = map(int, input().split())
        nodes[a - 1].children.append(b - 1)
        nodes[b - 1].children.append(a - 1)
    nodes[0].setParent(K, -1, 0, nodes)
    patterns = 1
    for node in nodes:
        patterns = (patterns * node.pattern) % 100000007
    print(patterns)

if __name__ == "__main__":
    solve()

