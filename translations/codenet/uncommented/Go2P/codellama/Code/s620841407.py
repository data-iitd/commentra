
import sys
import math

n, m = map(int, input().split())
edges = []
for i in range(n - 1):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    edges.append([x, y])

def f(x, y):
    return x * y % m

def g(v, p):
    return v + 1

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

        self.dp = [[0] * len(self.adjacents[i]) for i in range(len(self.adjacents))]
        self.res = [0] * len(self.adjacents)

        if self.node_count > 1:
            self.initialize()
        else:
            self.res[0] = self.operate_node(self.identity, 0)

    def query(self, node):
        return self.res[node]

    def initialize(self):
        parents, order = [0] * self.node_count, [0] * self.node_count

        # InitOrderedTree
        index = 0
        stack = [0]
        parents[0] = -1
        while stack:
            node = stack[-1]
            stack.pop()
            order[index] = node
            index += 1
            for i in range(len(self.adjacents[node])):
                adjacent = self.adjacents[node][i]
                if adjacent == parents[node]:
                    continue
                stack.append(adjacent)
                parents[adjacent] = node

        # fromLeaf
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

        # toLeaf
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

solver = ReRootingSolver(n, edges, 1, f, g)
for i in range(n):
    print(solver.query(i) - 1)

