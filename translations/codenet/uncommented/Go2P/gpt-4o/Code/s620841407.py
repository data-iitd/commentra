import sys
from collections import defaultdict

MOD = 1000000000 + 7

class ReRootingSolver:
    def __init__(self, node_count, edges, identity, operate, operate_node):
        self.node_count = node_count
        self.identity = identity
        self.operate = operate
        self.operate_node = operate_node

        self.adjacents = [[] for _ in range(node_count)]
        self.index_for_adjacents = [[] for _ in range(node_count)]
        for i, (x, y) in enumerate(edges):
            self.index_for_adjacents[x].append(len(self.adjacents[y]))
            self.index_for_adjacents[y].append(len(self.adjacents[x]))
            self.adjacents[x].append(y)
            self.adjacents[y].append(x)

        self.dp = [[self.identity] * len(adj) for adj in self.adjacents]
        self.res = [self.identity] * node_count

        if self.node_count > 1:
            self.initialize()
        else:
            self.res[0] = self.operate_node(self.identity, 0)

    def query(self, node):
        return self.res[node]

    def initialize(self):
        parents = [-1] * self.node_count
        order = []
        stack = [0]
        while stack:
            node = stack.pop()
            order.append(node)
            for adjacent in self.adjacents[node]:
                if adjacent != parents[node]:
                    stack.append(adjacent)
                    parents[adjacent] = node

        # fromLeaf
        for node in reversed(order[1:]):
            parent = parents[node]
            accum = self.identity
            parent_index = -1
            for j, adjacent in enumerate(self.adjacents[node]):
                if adjacent == parent:
                    parent_index = j
                    continue
                accum = self.operate(accum, self.dp[node][j])
            self.dp[parent][self.index_for_adjacents[node][parent_index]] = self.operate_node(accum, node)

        # toLeaf
        for node in order:
            accum = self.identity
            accums_from_tail = [self.identity] * (len(self.adjacents[node]) + 1)
            for j in range(len(accums_from_tail) - 1, 0, -1):
                accums_from_tail[j - 1] = self.operate(self.dp[node][j], accums_from_tail[j])
            for j, adjacent in enumerate(self.adjacents[node]):
                self.dp[adjacent][self.index_for_adjacents[node][j]] = self.operate_node(self.operate(accum, accums_from_tail[j]), node)
                accum = self.operate(accum, self.dp[node][j])
            self.res[node] = self.operate_node(accum, node)

def main():
    n, m = map(int, sys.stdin.readline().split())
    edges = [tuple(map(lambda x: int(x) - 1, sys.stdin.readline().split())) for _ in range(n - 1)]

    f = lambda x, y: (x * y) % m
    g = lambda v, p: v + 1
    solver = ReRootingSolver(n, edges, 1, f, g)

    for i in range(n):
        print(solver.query(i) - 1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
