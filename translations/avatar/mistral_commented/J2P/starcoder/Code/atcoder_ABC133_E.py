
import sys

class Node:
    def __init__(self, i):
        self.pattern = 0
        self.index = i
        self.children = []
        self.parent = -1

    def setParent(self, K, parent, use, nodes):
        self.pattern = K - use
        self.parent = parent
        count = 1
        if parent!= -1:
            count += 1
        for n in self.children:
            if n == self.parent:
                continue
            nodes[n].setParent(K, self.index, count, nodes)
            count += 1

    def solve(self):
        N, K = map(int, input().split())
        nodes = [Node(i) for i in range(N)]
        for i in range(N - 1):
            a, b = map(int, input().split())
            nodes[a - 1].children.append(b - 1)
            nodes[b - 1].children.append(a - 1)
        nodes[0].setParent(K, -1, 0, nodes)
        patterns = 1
        for i in range(N):
            patterns = (patterns * nodes[i].pattern) % 1_000_000_007
        print(patterns)

if __name__ == '__main__':
    obj = Node(0)
    obj.solve()

