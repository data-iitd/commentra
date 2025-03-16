

import sys
input = sys.stdin.readline

MOD = 10 ** 9 + 7

def main():
    N, M = map(int, input().split())
    edges = [[] for _ in range(N)]
    for _ in range(N - 1):
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        edges[x].append(y)
        edges[y].append(x)

    f = lambda x, y: (x * y) % M
    g = lambda v, p: v + 1

    # Initialize the disjoint set data structure
    class ReRootingSolver:
        def __init__(self, nodeCount, edges, identity, f, g):
            self.nodeCount = nodeCount
            self.identity = identity
            self.f = f
            self.g = g
            self.adjacents = [[] for _ in range(nodeCount)]
            self.indexForAdjacents = [[] for _ in range(nodeCount)]
            for i, e in enumerate(edges):
                self.indexForAdjacents[e[0]].append(len(self.adjacents[e[1]]))
                self.indexForAdjacents[e[1]].append(len(self.adjacents[e[0]]))
                self.adjacents[e[0]].append(e[1])
                self.adjacents[e[1]].append(e[0])
            self.dp = [[self.identity] * len(self.adjacents[i]) for i in range(self.nodeCount)]
            self.res = [self.identity] * self.nodeCount
            if self.nodeCount > 1:
                self.initialize()
            else:
                self.res[0] = self.g(self.identity, 0)

        def query(self, node):
            return self.res[node]

        def initialize(self):
            parents, order = [-1] * self.nodeCount, []
            stack = [0]
            while stack:
                node = stack.pop()
                order.append(node)
                for i in range(len(self.adjacents[node])):
                    adjacent = self.adjacents[node][i]
                    if adjacent == parents[node]:
                        continue
                    stack.append(adjacent)
                    parents[adjacent] = node
            for i in range(len(order) - 1, 0, -1):
                node = order[i]
                parent = parents[node]
                accum = self.identity
                parentIndex = -1
                for j in range(len(self.adjacents[node])):
                    if self.adjacents[node][j] == parent:
                        parentIndex = j
                        continue
                    accum = self.f(accum, self.dp[node][j])
                self.dp[parent][self.indexForAdjacents[node][parentIndex]] = self.g(accum, node)
                accum = self.f(accum, self.dp[node][j])
                self.dp[node][j] = accum
            for i in range(len(order)):
                node = order[i]
                accum = self.identity
                accumsFromTail = [self.identity] * len(self.adjacents[node])
                accumsFromTail[-1] = self.identity
                for j in range(len(accumsFromTail) - 1, 0, -1):
                    accumsFromTail[j - 1] = self.f(self.dp[node][j], accumsFromTail[j])
                for j in range(len(accumsFromTail)):
                    self.dp[self.adjacents[node][j]][self.indexForAdjacents[node][j]] = self.g(self.f(accum, accumsFromTail[j]), node)
                    accum = self.f(accum, self.dp[node][j])
                self.res[node] = self.g(accum, node)

    solver = ReRootingSolver(N, edges, 1, f, g)
    for i in range(N):
        print(solver.query(i) - 1)

if __name__ == "__main__":
    main()

