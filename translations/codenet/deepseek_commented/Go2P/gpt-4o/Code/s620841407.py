import sys
from collections import defaultdict
from math import inf

# Constants used throughout the program
MOD = 1000000000 + 7
ALPHABET_NUM = 26
NIL = -1

# ReRootingSolver class for solving the re-rooting problem
class ReRootingSolver:
    def __init__(self, node_count, edges, identity, operate, operate_node):
        self.node_count = node_count
        self.identity = identity
        self.operate = operate
        self.operate_node = operate_node

        self.adjacents = [[] for _ in range(node_count)]
        self.index_for_adjacents = [[] for _ in range(node_count)]
        for e in edges:
            self.index_for_adjacents[e[0]].append(len(self.adjacents[e[1]]))
            self.index_for_adjacents[e[1]].append(len(self.adjacents[e[0]]))
            self.adjacents[e[0]].append(e[1])
            self.adjacents[e[1]].append(e[0])

        self.dp = [[self.identity] * len(adj) for adj in self.adjacents]
        self.res = [self.identity] * self.node_count

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
        index = 0

        while stack:
            node = stack.pop()
            order.append(node)
            for adjacent in self.adjacents[node]:
                if adjacent != parents[node]:
                    stack.append(adjacent)
                    parents[adjacent] = node

        # fromLeaf computes values starting from the leaves
        for i in range(len(order) - 1, 0, -1):
            node = order[i]
            parent = parents[node]

            accum = self.identity
            parent_index = -1
            for j in range(len(self.adjacents[node])):
                if self.adjacents[node][j] == parent:
                    parent_index = j
                    continue
                accum = self.operate(accum, self.dp[node][j])
            self.dp[parent][self.index_for_adjacents[node][parent_index]] = self.operate_node(accum, node)

        # toLeaf computes values propagating from leaves to the root
        for i in range(len(order)):
            node = order[i]
            accum = self.identity
            accums_from_tail = [self.identity] * len(self.adjacents[node])
            accums_from_tail[-1] = self.identity
            for j in range(len(accums_from_tail) - 1, 0, -1):
                accums_from_tail[j - 1] = self.operate(self.dp[node][j], accums_from_tail[j])
            for j in range(len(accums_from_tail)):
                self.dp[self.adjacents[node][j]][self.index_for_adjacents[node][j]] = self.operate_node(self.operate(accum, accums_from_tail[j]), node)
                accum = self.operate(accum, self.dp[node][j])
            self.res[node] = self.operate_node(accum, node)

# Read input
def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

# Main function to execute the program
def main():
    n, m = read_ints()
    edges = [read_ints() for _ in range(n - 1)]
    edges = [[x - 1, y - 1] for x, y in edges]  # Convert to 0-indexed

    # Define the operations for the ReRootingSolver
    f = lambda x, y: (x * y) % m
    g = lambda v, p: v + 1

    # Initialize and use the ReRootingSolver to compute the results
    solver = ReRootingSolver(n, edges, 1, f, g)
    for i in range(n):
        print(solver.query(i) - 1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
