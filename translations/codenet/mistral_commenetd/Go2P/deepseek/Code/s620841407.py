import sys
import io
import os
import math
from collections import defaultdict

# General purpose
MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = math.inf
INF_BIT60 = 1 << 60
INF_INT32 = math.inf
INF_BIT30 = 1 << 30
NIL = -1

# for dijkstra, prim, and so on
WHITE = 0
GRAY = 1
BLACK = 2

input_text = """
"""
sys.stdin = io.StringIO(input_text.strip())

def input():
    return sys.stdin.readline().strip()

def read_int():
    return int(input())

def read_int_list():
    return list(map(int, input().split()))

def read_float():
    return float(input())

def read_float_list():
    return list(map(float, input().split()))

def read_str():
    return input()

def read_str_list():
    return input().split()

def zero_padding_rune_slice(num, length):
    return (num).zfill(length)

def print_ints_line(ints):
    print(" ".join(map(str, ints)))

class T(int):
    pass

class ReRootingSolver:
    def __init__(self, node_count, edges, identity, operate, operate_node):
        self.NodeCount = node_count
        self.Adjacents = [[] for _ in range(node_count)]
        self.IndexForAdjacents = [[] for _ in range(node_count)]
        self.Res = [identity] * node_count
        self.DP = [[] for _ in range(node_count)]
        self.Identity = identity
        self.Operate = operate
        self.OperateNode = operate_node

        for x, y in edges:
            self.IndexForAdjacents[x].append(len(self.Adjacents[y]))
            self.IndexForAdjacents[y].append(len(self.Adjacents[x]))
            self.Adjacents[x].append(y)
            self.Adjacents[y].append(x)

        for i in range(len(self.Adjacents)):
            self.DP[i] = [identity] * len(self.Adjacents[i])

        if self.NodeCount > 1:
            self.Initialize()

    def Query(self, node):
        return self.Res[node]

    def Initialize(self):
        parents = [-1] * self.NodeCount
        order = []

        # InitOrderedTree
        stack = [0]
        parents[0] = -1
        while stack:
            node = stack.pop()
            order.append(node)
            for adjacent in self.Adjacents[node]:
                if adjacent == parents[node]:
                    continue
                stack.append(adjacent)
                parents[adjacent] = node

        # fromLeaf
        for i in range(len(order) - 1, 0, -1):
            node = order[i]
            parent = parents[node]
            accum = self.Identity
            parent_index = -1
            for j, adjacent in enumerate(self.Adjacents[node]):
                if adjacent == parent:
                    parent_index = j
                    continue
                accum = self.Operate(accum, self.DP[node][j])
            self.DP[parent][self.IndexForAdjacents[node][parent_index]] = self.OperateNode(accum, node)
            accum = self.Operate(accum, self.DP[node][j])
            self.DP[node][j] = accum

        # toLeaf
        for i in range(len(order)):
            node = order[i]
            accum = self.Identity
            accums_from_tail = [self.Identity] * len(self.Adjacents[node])
            for j in range(len(accums_from_tail) - 1, 0, -1):
                accums_from_tail[j - 1] = self.Operate(self.DP[node][j], accums_from_tail[j])
            for j in range(len(accums_from_tail)):
                self.DP[self.Adjacents[node][j]][self.IndexForAdjacents[node][j]] = self.OperateNode(self.Operate(accum, accums_from_tail[j]), node)
                accum = self.Operate(accum, self.DP[node][j])
            self.Res[node] = self.OperateNode(accum, node)

# Example usage
if __name__ == "__main__":
    n, m = read_int_list()
    edges = []
    for _ in range(n - 1):
        x, y = read_int_list()
        edges.append((x - 1, y - 1))

    f = lambda x, y: T(int(x) * int(y) % m)
    g = lambda v, p: v + 1
    s = ReRootingSolver(n, edges, 1, f, g)

    for i in range(n):
        print(s.Query(i) - 1)
