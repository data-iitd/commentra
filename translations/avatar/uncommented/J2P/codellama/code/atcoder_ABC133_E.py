
import sys
import math

class Node:
    def __init__(self, index):
        self.pattern = 0
        self.index = index
        self.children = []
        self.parent = -1

    def setParent(self, K, parent, use, nodes):
        self.pattern = K - use
        self.parent = parent
        count = 1
        if parent != -1:
            count += 1
        for n in self.children:
            if n == self.parent:
                continue
            nodes[n].setParent(K, self.index, count, nodes)
            count += 1

def solve():
    N = int(sys.stdin.readline())
    K = int(sys.stdin.readline())
    nodes = [Node(i) for i in range(N)]
    for i in range(N - 1):
        a, b = map(int, sys.stdin.readline().split())
        a -= 1
        b -= 1
        nodes[a].children.append(b)
        nodes[b].children.append(a)
    nodes[0].setParent(K, -1, 0, nodes)
    patterns = 1
    for i in range(N):
        patterns = (patterns * nodes[i].pattern) % 1000000007
    print(patterns)

solve()

