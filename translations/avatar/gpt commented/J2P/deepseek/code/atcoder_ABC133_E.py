class Node:
    def __init__(self, index):
        self.pattern = 0
        self.index = index
        self.children = []
        self.parent = -1

    def set_parent(self, K, parent, use, nodes):
        self.pattern = K - use
        self.parent = parent
        count = 1

        if parent != -1:
            count += 1

        for child in self.children:
            if child == self.parent:
                continue
            nodes[child].set_parent(K, self.index, count, nodes)
            count += 1

class Main:
    def __init__(self):
        pass

    def solve(self):
        inp = input().split()
        N = int(inp[0])
        K = int(inp[1])
        nodes = [Node(i) for i in range(N)]

        for _ in range(N - 1):
            a, b = map(int, input().split())
            nodes[a - 1].children.append(b - 1)
            nodes[b - 1].children.append(a - 1)

        nodes[0].set_parent(K, -1, 0, nodes)

        patterns = 1
        for node in nodes:
            patterns = (patterns * node.pattern) % 1_000_000_007

        print(patterns)

if __name__ == "__main__":
    main = Main()
    main.solve()
