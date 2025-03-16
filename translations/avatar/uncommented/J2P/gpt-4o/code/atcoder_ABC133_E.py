from collections import deque

class Node:
    def __init__(self, i):
        self.pattern = 0
        self.index = i
        self.children = []
        self.parent = -1

    def set_parent(self, K, parent, use, nodes):
        self.pattern = K - use
        self.parent = parent
        count = 1
        if parent != -1:
            count += 1
        for n in self.children:
            if n == self.parent:
                continue
            nodes[n].set_parent(K, self.index, count, nodes)
            count += 1

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    K = int(data[1])
    
    nodes = [Node(i) for i in range(N)]
    
    index = 2
    for _ in range(N - 1):
        a = int(data[index]) - 1
        b = int(data[index + 1]) - 1
        nodes[a].children.append(b)
        nodes[b].children.append(a)
        index += 2
    
    nodes[0].set_parent(K, -1, 0, nodes)
    
    patterns = 1
    for i in range(N):
        patterns = (patterns * nodes[i].pattern) % 1_000_000_007
    
    print(patterns)

if __name__ == "__main__":
    solve()

# <END-OF-CODE>
