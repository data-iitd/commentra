

import bufio
import math
import os
import sys

# Constants for buffer sizes and modulo value
initialBufSize = 10000
maxBufSize = 1000000
mod = 100000007

# Scanner for reading input
sc = bufio.Scanner(os.stdin, initialBufSize=initialBufSize, maxBufSize=maxBufSize)
sc.buffer(bytearray(os.read(0, os.fstat(0).st_size)), maxBufSize)
sc.whitespace_split = False

def getInt():
    sc.scan()
    return int(sc.token())

def getIntArray(n):
    array = [0] * n
    for i in range(n):
        array[i] = getInt()
    return array

def getString():
    sc.scan()
    return sc.token().decode()

def getStringArray(n):
    array = [""] * n
    for i in range(n):
        array[i] = getString()
    return array

def abs(a):
    return int(math.fabs(a))

def pow(p, q):
    return int(math.pow(p, q))

def powMod(n, p):
    if p == 0:
        return 1
    elif p % 2 == 0:
        t = powMod(n, p // 2)
        return calcMod(t * t)
    else:
        return calcMod(n * powMod(n, p - 1))

def min(*args):
    if len(args) == 0:
        raise Exception("function min() requires at least one argument.")
    res = args[0]
    for i in range(1, len(args)):
        res = min(res, args[i])
    return res

def max(*args):
    if len(args) == 0:
        raise Exception("function max() requires at least one argument.")
    res = args[0]
    for i in range(1, len(args)):
        res = max(res, args[i])
    return res

def strSearch(a, b):
    for i in range(len(a)):
        if a[i] == b:
            return True
    return False

def printIntArray(array):
    sys.stdout.write(" ".join(map(str, array)))
    sys.stdout.write("\n")

def calcMod(x):
    return x % mod

def reverse(s):
    return s[::-1]

def isPrime(n):
    if n < 2:
        return False
    elif n == 2:
        return True
    elif n % 2 == 0:
        return False
    sqrtN = int(math.sqrt(n))
    for i in range(3, sqrtN + 1, 2):
        if n % i == 0:
            return False
    return True

def contains(s, e):
    return e in s

def makeRange(min, max):
    return list(range(min, max + 1))

def powerset2(nums):
    length = int(math.pow(2, len(nums)))
    result = [[] for _ in range(length)]
    index = 0
    result[index] = []
    index += 1
    for n in nums:
        max = index
        for i in range(max):
            result[index] = copyAndAppend(result[i], n)
            index += 1
    return result

def copyAndAppend(nums, n):
    dst = nums[:]
    dst.append(n)
    return dst

def calcGcd(x, y):
    if y == 0:
        return x
    elif x >= y:
        return calcGcd(y, x % y)
    else:
        return calcGcd(x, y % x)

def getDivisor(n):
    divisor = set()
    divisor.add(1)
    if n!= 1:
        divisor.add(n)
    sqrt = int(math.sqrt(n))
    for i in range(2, sqrt + 1):
        if n % i == 0:
            divisor.add(i)
            divisor.add(n // i)
    return list(divisor)

class Graph:
    def __init__(self, n):
        self.n = n
        self.edges = [[] for _ in range(n)]

    def addEdge(self, u, v):
        self.edges[v].append(u)
        self.edges[u].append(v)

def dfs(c, edges, visited):
    visited[c] = True
    for v in edges[c]:
        if not visited[v]:
            dfs(v, edges, visited)

def bfs(c, graph):
    next = [c]
    visited = set()
    while next:
        u = next.pop(0)
        visited.add(u)
        for v in graph.edges[u]:
            if v not in visited:
                next.append(v)

