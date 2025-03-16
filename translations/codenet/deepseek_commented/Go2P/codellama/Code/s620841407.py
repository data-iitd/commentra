
import sys
import math

# Go:
# package main

# import (
# 	"bufio"
# 	"fmt"
# 	"io"
# 	"math"
# 	"os"
# 	"strconv"
# )

# /********** FAU standard libraries **********/

# //fmt.Sprintf("%b\n", 255) 	// binary expression

# /********** I/O usage **********/

# //str := ReadString()
# //i := ReadInt()
# //X := ReadIntSlice(n)
# //S := ReadRuneSlice()
# //a := ReadFloat64()
# //A := ReadFloat64Slice(n)

# //str := ZeroPaddingRuneSlice(num, 32)
# //str := PrintIntsLine(X...)

# /*******************************************************************/

# // Constants used throughout the program
# MOD = 1000000000 + 7
# # MOD          = 998244353
# ALPHABET_NUM = 26
# INF_INT64    = math.MaxInt64
# INF_BIT60    = 1 << 60
# INF_INT32    = math.MaxInt32
# INF_BIT30    = 1 << 30
# NIL          = -1

# // for dijkstra, prim, and so on
# WHITE = 0
# GRAY  = 1
# BLACK = 2

# // Initializes the input reader and output writer
# def init():
#     # bufio.ScanWords <---> bufio.ScanLines
#     global ReadString
#     ReadString = newReadString(sys.stdin, sys.stdin.readline)
#     global stdout
#     stdout = sys.stdout

# // Global variables
# n, m = 0, 0
# edges = []

# // Main function to execute the program
# def main():
#     # Read the number of nodes and edges
#     n, m = map(int, ReadString().split())

#     # Construct the graph from the edges
#     for i in range(n - 1):
#         x, y = map(int, ReadString().split())
#         x -= 1
#         y -= 1

#         e = [x, y]
#         edges.append(e)

#     # Define the operations for the ReRootingSolver
#     f = lambda x, y: x * y % m
#     g = lambda v, p: v + 1

#     # Initialize and use the ReRootingSolver to compute the results
#     s = NewReRootingSolver(n, edges, 1, f, g)
#     for i in range(n):
#         print(s.Query(i) - 1)

# # T is a type alias for integers used in the ReRootingSolver
# T = int

# # ReRootingSolver struct for solving the re-rooting problem
# class ReRootingSolver:
#     def __init__(self, nodeCount, edges, identity, operate, operateNode):
#         self.NodeCount = nodeCount
#         self.Identity = identity
#         self.Operate = operate
#         self.OperateNode = operateNode

#         self.Adjacents = [[] for _ in range(nodeCount)]
#         self.IndexForAdjacents = [[] for _ in range(nodeCount)]
#         for e in edges:
#             self.IndexForAdjacents[e[0]].append(len(self.Adjacents[e[1]]))
#             self.IndexForAdjacents[e[1]].append(len(self.Adjacents[e[0]]))
#             self.Adjacents[e[0]].append(e[1])
#             self.Adjacents[e[1]].append(e[0])

#         self.DP = [[0 for _ in range(len(self.Adjacents[i]))] for i in range(len(self.Adjacents))]
#         self.Res = [0 for _ in range(len(self.Adjacents))]

#         if self.NodeCount > 1:
#             self.Initialize()
#         else:
#             self.Res[0] = self.OperateNode(self.Identity, 0)

#     # Query returns the result for a given node
#     def Query(self, node):
#         return self.Res[node]

#     # Initialize computes the dynamic programming values
#     def Initialize(self):
#         parents, order = [0 for _ in range(self.NodeCount)], [0 for _ in range(self.NodeCount)]

#         # InitOrderedTree initializes the tree in a way that is useful for traversal
#         index = 0
#         stack = [0]
#         parents[0] = -1
#         while len(stack) > 0:
#             node = stack[-1]
#             stack.pop()
#             order[index] = node
#             index += 1
#             for i in range(len(self.Adjacents[node])):
#                 adjacent = self.Adjacents[node][i]
#                 if adjacent == parents[node]:
#                     continue
#                 stack.append(adjacent)
#                 parents[adjacent] = node

#         # fromLeaf computes values starting from the leaves
#         for i in range(len(order) - 1, 0, -1):
#             node = order[i]
#             parent = parents[node]

#             accum = self.Identity
#             parentIndex = -1
#             for j in range(len(self.Adjacents[node])):
#                 if self.Adjacents[node][j] == parent:
#                     parentIndex = j
#                     continue
#                 accum = self.Operate(accum, self.DP[node][j])
#             self.DP[parent][self.IndexForAdjacents[node][parentIndex]] = self.OperateNode(accum, node)

#         # toLeaf computes values propagating from leaves to the root
#         for i in range(len(order)):
#             node = order[i]
#             accum = self.Identity
#             accumsFromTail = [0 for _ in range(len(self.Adjacents[node]))]
#             accumsFromTail[-1] = self.Identity
#             for j in range(len(accumsFromTail) - 1, 0, -1):
#                 accumsFromTail[j - 1] = self.Operate(self.DP[node][j], accumsFromTail[j])
#             for j in range(len(accumsFromTail)):
#                 self.DP[self.Adjacents[node][j]][self.IndexForAdjacents[node][j]] = self.OperateNode(self.Operate(accum, accumsFromTail[j]), node)
#                 accum = self.Operate(accum, self.DP[node][j])
#             self.Res[node] = self.OperateNode(accum, node)

# 