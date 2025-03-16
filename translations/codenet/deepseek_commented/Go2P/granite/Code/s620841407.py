

import sys
import io
import os
import math
import heapq
import queue
import bisect
import random
import time
import re
import string
from decimal import *

# Read instance from stdin / file
def ReadString():
    return sys.stdin.readline().rstrip()
def ReadInt():
    return int(ReadString())
def ReadInt2():
    return [int(x) for x in ReadString().split()]
def ReadInt64():
    return int(ReadString())
def ReadInt64_2():
    return [int(x) for x in ReadString().split()]
def ReadInt64Slice(n):
    return [int(ReadString()) for i in range(n)]
def ReadFloat64():
    return float(ReadString())
def ReadFloat64Slice(n):
    return [float(ReadString()) for i in range(n)]
def ReadRuneSlice():
    return list(ReadString())

# Write instance to stdout / file
stdout = io.TextIOWrapper(sys.stdout.buffer, 'utf-8')
def PrintfBufStdout(s):
    stdout.write(s)
    stdout.flush()

# Constants
MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = math.inf
INF_BIT60 = 1 << 60
INF_INT32 = math.inf
INF_BIT30 = 1 << 30
NIL = -1

# Global variables
n, m = 0, 0
edges = []

# Main function
def main():
    global n, m, edges
    n, m = ReadInt2()
    for i in range(n - 1):
        x, y = ReadInt2()
        x -= 1
        y -= 1
        edges.append([x, y])

    # Define the operations for the ReRootingSolver
    f = lambda x, y: (x + y) % m
    g = lambda v, p: v + 1

    # Initialize and use the ReRootingSolver
    s = ReRootingSolver(n, edges, 1, f, g)
    for i in range(n):
        PrintfBufStdout(str(s.Query(i) - 1) + '\n')

# ReRootingSolver class for solving the re-rooting problem
class ReRootingSolver:
    def __init__(self, nodeCount, edges, identity, operate, operateNode):
        self.NodeCount = nodeCount
        self.Identity = identity
        self.Operate = operate
        self.OperateNode = operateNode

        self.Adjacents = [[] for i in range(nodeCount)]
        self.IndexForAdjacents = [[] for i in range(nodeCount)]
        for e in edges:
            self.IndexForAdjacents[e[0]].append(len(self.Adjacents[e[1]]))
            self.IndexForAdjacents[e[1]].append(len(self.Adjacents[e[0]]))
            self.Adjacents[e[0]].append(e[1])
            self.Adjacents[e[1]].append(e[0])

        self.DP = [[identity for j in range(len(self.Adjacents[i]))] for i in range(len(self.Adjacents))]
        self.Res = [identity for i in range(len(self.Adjacents))]

        if self.NodeCount > 1:
            self.Initialize()
        else:
            self.Res[0] = self.OperateNode(self.Identity, 0)

    # Query returns the result for a given node
    def Query(self, node):
        return self.Res[node]

    # Initialize computes the dynamic programming values
    def Initialize(self):
        parents = [0] * self.NodeCount
        order = []
        stack = [0]
        parents[0] = -1
        while len(stack) > 0:
            node = stack.pop()
            order.append(node)
            for i in range(len(self.Adjacents[node])):
                adjacent = self.Adjacents[node][i]
                if adjacent == parents[node]:
                    continue
                stack.append(adjacent)
                parents[adjacent] = node
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
        for i in range(len(order)):
            node = order[i]
            accum = self.Identity
            accumsFromTail = [self.Identity for j in range(len(self.Adjacents[node]))]
            accumsFromTail[-1] = self.Identity
            for j in range(len(accumsFromTail) - 1, 0, -1):
                accumsFromTail[j - 1] = self.Operate(self.DP[node][j], accumsFromTail[j])
            for j in range(len(accumsFromTail)):
                self.DP[self.Adjacents[node][j]][self.IndexForAdjacents[node][j]] = self.OperateNode(self.Operate(accum, accumsFromTail[j]), node)
                accum = self.Operate(accum, self.DP[node][j])
        for i in range(len(order)):
            node = order[i]
            self.Res[node] = self.OperateNode(accum, node)

    # Other methods and functions...

# Run the main function
if __name__ == '__main__':
    main()

