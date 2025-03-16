import sys
import io
import os
import math
import re
import string
import bisect
import collections
from itertools import *
from functools import *
from heapq import *
from copy import *
from operator import *
from bisect import *
from collections import *

# Constants used throughout the program
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

# Initializes the input reader and output writer
def init():
    global input_reader, output_writer
    input_reader = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
    output_writer = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')

# Global variables
n, m = 0, 0
edges = []

# Main function to execute the program
def main():
    global n, m, edges
    # Read the number of nodes and edges
    n, m = map(int, input().split())

    # Construct the graph from the edges
    for _ in range(n - 1):
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        edges.append([x, y])

    # Define the operations for the ReRootingSolver
    def f(x, y):
        return (x * y) % m

    def g(v, p):
        return v + 1

    # Initialize and use the ReRootingSolver to compute the results
    s = NewReRootingSolver(n, edges, 1, f, g)
    for i in range(n):
        print(s.Query(i) - 1)

# T is a type alias for integers used in the ReRootingSolver
T = int

# ReRootingSolver struct for solving the re-rooting problem
class ReRootingSolver:
    def __init__(self, nodeCount, edges, identity, operate, operateNode):
        self.NodeCount = nodeCount
        self.Identity = identity
        self.Operate = operate
        self.OperateNode = operateNode

        self.Adjacents = [[] for _ in range(nodeCount)]
        self.IndexForAdjacents = [[] for _ in range(nodeCount)]

        for e in edges:
            self.IndexForAdjacents[e[0]].append(len(self.Adjacents[e[1]]))
            self.IndexForAdjacents[e[1]].append(len(self.Adjacents[e[0]]))
            self.Adjacents[e[0]].append(e[1])
            self.Adjacents[e[1]].append(e[0])

        self.DP = [[] for _ in range(len(self.Adjacents))]
        self.Res = [0] * len(self.Adjacents)

        if self.NodeCount > 1:
            self.Initialize()
        else:
            self.Res[0] = self.OperateNode(self.Identity, 0)

    def Query(self, node):
        return self.Res[node]

    def Initialize(self):
        parents = [-1] * self.NodeCount
        order = [0] * self.NodeCount

        # InitOrderedTree initializes the tree in a way that is useful for traversal
        index = 0
        stack = [0]
        parents[0] = -1
        while stack:
            node = stack[-1]
            stack.pop()
            order[index] = node
            index += 1
            for adjacent in self.Adjacents[node]:
                if adjacent == parents[node]:
                    continue
                stack.append(adjacent)
                parents[adjacent] = node

        # fromLeaf computes values starting from the leaves
        for i in range(len(order) - 1, 0, -1):
            node = order[i]
            parent = parents[node]

            accum = self.Identity
            parentIndex = -1
            for j in range(len(self.Adjacents[node])):
                if self.Adjacents[node][j] == parent:
                    parentIndex = j
                    continue
                accum = self.Operate(accum, self.DP[node][j])
            self.DP[parent][self.IndexForAdjacents[node][parentIndex]] = self.OperateNode(accum, node)

        # toLeaf computes values propagating from leaves to the root
        for i in range(len(order)):
            node = order[i]
            accum = self.Identity
            accumsFromTail = [self.Identity] * len(self.Adjacents[node])
            accumsFromTail[-1] = self.Identity
            for j in range(len(accumsFromTail) - 1, 0, -1):
                accumsFromTail[j - 1] = self.Operate(self.DP[node][j], accumsFromTail[j])
            for j in range(len(accumsFromTail)):
                self.DP[self.Adjacents[node][j]][self.IndexForAdjacents[node][j]] = self.OperateNode(self.Operate(accum, accumsFromTail[j]), node)
                accum = self.Operate(accum, self.DP[node][j])
            self.Res[node] = self.OperateNode(accum, node)

# Initialize the input reader and output writer
init()
main()
