# URL:
# https://atcoder.jp/contests/dp/tasks/dp_v

import sys
import io
import os
import math
import bisect
import heapq
import itertools
import string
import queue
import copy
import time
from operator import itemgetter
from collections import deque, Counter, defaultdict
from functools import lru_cache

# Constants for general purpose usage
MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = math.inf
INF_BIT60 = 1 << 60
INF_INT32 = math.inf
INF_BIT30 = 1 << 30
NIL = -1
WHITE = 0
GRAY = 1
BLACK = 2

# Initialization function to set up input and output
def init():
    global input_reader, output_writer
    input_reader = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
    output_writer = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')

# Global variables for the number of nodes and edges
n, m = 0, 0
edges = []

def main():
    global n, m, edges
    # Read the number of nodes and edges
    n, m = map(int, input_reader.readline().split())
    # Read edges and build the adjacency list
    edges = [[] for _ in range(n)]
    for _ in range(n - 1):
        x, y = map(int, input_reader.readline().split())
        x -= 1
        y -= 1
        edges[x].append(y)
        edges[y].append(x)

    # Define operations for the re-rooting solver
    def f(x, y):
        return x * y % m

    def g(v, p):
        return v + 1

    # Create a new re-rooting solver instance
    s = ReRootingSolver(n, edges, 1, f, g)
    # Query results for each node and print them
    for i in range(n):
        print(s.query(i) - 1)

# Type definition for generic operations
T = int

# Structure for the re-rooting solver
class ReRootingSolver:
    def __init__(self, node_count, edges, identity, operate, operate_node):
        self.NodeCount = node_count
        self.Adjacents = edges
        self.Identity = identity
        self.Operate = operate
        self.OperateNode = operate_node
        self.DP = [[] for _ in range(node_count)]
        self.Res = [self.Identity] * node_count
        self.IndexForAdjacents = [[] for _ in range(node_count)]
        for i in range(len(edges)):
            for j in range(len(edges[i])):
                self.IndexForAdjacents[edges[i][j]].append(len(edges[edges[i][j]]))
                edges[edges[i][j]].append(i)
        if node_count > 1:
            self.Initialize()

    def query(self, node):
        return self.Res[node]

    def Initialize(self):
        parents = [-1] * self.NodeCount
        order = [0] * self.NodeCount
        index = 0
        stack = [0]
        parents[0] = -1
        while stack:
            node = stack.pop()
            order[index] = node
            index += 1
            for adjacent in self.Adjacents[node]:
                if adjacent == parents[node]:
                    continue
                stack.append(adjacent)
                parents[adjacent] = node
        for i in range(len(order) - 1, 0, -1):
            node = order[i]
            parent = parents[node]
            accum = self.Identity
            parent_index = -1
            for j in range(len(self.Adjacents[node])):
                if self.Adjacents[node][j] == parent:
                    parent_index = j
                    continue
                accum = self.Operate(accum, self.DP[node][j])
            self.DP[parent][self.IndexForAdjacents[node][parent_index]] = self.OperateNode(accum, node)
        for i in range(len(order)):
            node = order[i]
            accum = self.Identity
            accums_from_tail = [self.Identity] * len(self.Adjacents[node])
            accums_from_tail[-1] = self.Identity
            for j in range(len(accums_from_tail) - 1, 0, -1):
                accums_from_tail[j - 1] = self.Operate(self.DP[node][j], accums_from_tail[j])
            for j in range(len(accums_from_tail)):
                self.DP[self.Adjacents[node][j]][self.IndexForAdjacents[node][j]] = self.OperateNode(self.Operate(accum, accums_from_tail[j]), node)
                accum = self.Operate(accum, self.DP[node][j])
            self.Res[node] = self.OperateNode(accum, node)

# Initialize input and output
init()
main()
