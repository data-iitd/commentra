
import sys

class Node:
    def __init__(self, index):
        self.pattern = 0
        self.index = index
        self.children = []
        self.parent = -1

def setParent(K, parent, use, nodes):
    node.pattern = K - use
    node.parent = parent
    count = 1
    if parent!= -1:
        count += 1
    for n in node.children:
        if n == node.parent:
            continue
        setParent(K, node.index, count, nodes)
        count += 1

def solve():
    N = int(input())
    K = int(input())
    nodes = [Node(i) for i in range(N)]
    for i in range(N - 1):
        a = int(input()) - 1
        b = int(input()) - 1
        nodes[a].children.append(b)
        nodes[b].children.append(a)
    nodes[0].setParent(K, -1, 0, nodes)
    patterns = 1
    for i in range(N):
        patterns = (patterns * nodes[i].pattern) % 1_000_000_007
    print(patterns)

if __name__ == "__main__":
    solve()

# 