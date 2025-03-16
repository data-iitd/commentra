import sys
from collections import defaultdict

MOD = 1000000000 + 7  # Modulus for calculations

class ReRootingSolver:
    def __init__(self, node_count, edges, identity, operate, operate_node):
        self.node_count = node_count
        self.adjacents = defaultdict(list)
        self.index_for_adjacents = defaultdict(list)
        self.res = [identity] * node_count
        self.dp = [[identity] * node_count for _ in range(node_count)]
        self.identity = identity
        self.operate = operate
        self.operate_node = operate_node

        for x, y in edges:
            self.adjacents[x].append(y)
            self.adjacents[y].append(x)

        if self.node_count > 1:
            self.initialize()

    def query(self, node):
        return self.res[node]

    def initialize(self):
        parents = [-1] * self.node_count
        order = []
        stack = [0]
        index = 0

        while stack:
            node = stack.pop()
            order.append(node)
            for adjacent in self.adjacents[node]:
                if adjacent != parents[node]:
                    stack.append(adjacent)
                    parents[adjacent] = node

        for i in range(len(order) - 1, 0, -1):
            node = order[i]
            parent = parents[node]
            accum = self.identity
            parent_index = -1

            for j, adjacent in enumerate(self.adjacents[node]):
                if adjacent == parent:
                    parent_index = j
                    continue
                accum = self.operate(accum, self.dp[node][j])

            self.dp[parent][self.index_for_adjacents[node][parent_index]] = self.operate_node(accum, node)

        for i in range(len(order)):
            node = order[i]
            accum = self.identity
            accums_from_tail = [self.identity] * len(self.adjacents[node])

            for j in range(len(accums_from_tail) - 1, 0, -1):
                accums_from_tail[j - 1] = self.operate(self.dp[node][j], accums_from_tail[j])

            for j in range(len(accums_from_tail)):
                self.dp[self.adjacents[node][j]][self.index_for_adjacents[node][j]] = self.operate_node(self.operate(accum, accums_from_tail[j]), node)
                accum = self.operate(accum, self.dp[node][j])

            self.res[node] = self.operate_node(accum, node)

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def main():
    n, m = read_ints()
    edges = [tuple(read_ints()) for _ in range(n - 1)]

    f = lambda x, y: (x * y) % m  # Multiplication operation
    g = lambda v, p: v + 1         # Increment operation

    solver = ReRootingSolver(n, edges, 1, f, g)

    for i in range(n):
        print(solver.query(i) - 1)  # Output the result for each node

if __name__ == "__main__":
    main()

# <END-OF-CODE>
