import sys
import math
import re
from io import StringIO

# Custom Sorting Types
class Pair:
    def __init__(self, index, p1, p2):
        self.index = index
        self.p1 = p1
        self.p2 = p2

class Pairs(list):
    def __init__(self, *args):
        super().__init__(*args)

    def Len(self):
        return len(self)

    def Less(self, i, j):
        return self[i].index < self[j].index

    def Swap(self, i, j):
        self[i], self[j] = self[j], self[i]

class Int64Slice(list):
    def Len(self):
        return len(self)

    def Less(self, i, j):
        return self[i] < self[j]

    def Swap(self, i, j):
        self[i], self[j] = self[j], self[i]

def Int64s(a):
    a.sort()

def Int64sSliceAreSorted(a):
    return sorted(a) == a

# Constants and Variables
initialBufSize = 1e4
maxBufSize = 1e8
INF = 1e8

# scanner and writer are initialized for reading from standard input and writing to standard output.
buf = bytearray(initialBufSize)
scanner = bufio.Scanner(sys.stdin.buffer, buf)
writer = bufio.Writer(sys.stdout)
di = [-1, 0, 1, 0]
dj = [0, -1, 0, 1]

# Main Function
def main():
    buf = bytearray(initialBufSize)
    scanner.buffer(buf, maxBufSize)
    scanner.split(bufio.ScanWords)
    A, B, C = readInt(), readInt(), readInt()
    if C >= A and C <= B:
        print("Yes")
    else:
        print("No")

# Library
def NextPermutation(x):
    n = len(x) - 1
    if n < 1:
        return False
    j = n - 1
    while not (x[j] < x[j + 1]):
        j -= 1
        if j == -1:
            return False
    l = n
    while not (x[j] < x[l]):
        l -= 1
    x[j], x[l] = x[l], x[j]
    x[j + 1:] = reversed(x[j + 1:])
    return True

def doubleAry(h, w, init):
    res = [[init for _ in range(w)] for _ in range(h)]
    return res

def aryEq(a, b):
    return a == b

def clone(n):
    return n[:]

def write(s):
    writer.write(s)

def print():
    writer.flush()

def readLine():
    return sys.stdin.readline().strip()

def readInt():
    return int(sys.stdin.readline().strip())

def readFloat():
    return float(sys.stdin.readline().strip())

def readRunes():
    return list(sys.stdin.readline().strip())

def readString():
    return sys.stdin.readline().strip()

def readStrings():
    return sys.stdin.readline().strip().split()

def s2i(s):
    return int(s)

def i2s(i):
    return str(i)

def s2f(s):
    return float(s)

def abs(i):
    return abs(i)

def max(a, *args):
    return max(a, *args)

def min(a, *args):
    return min(a, *args)

def sum(i):
    return sum(i)

def split(s):
    return s.split()

def strAry2intAry(strs):
    return [s2i(s) for s in strs]

def intAry2strAry(nums):
    return [i2s(n) for n in nums]

def ary2str(strs):
    return ' '.join(strs)

def reverse(res):
    return res[::-1]

def ini(res, init):
    if len(res) == 0:
        return
    res[0] = init
    for i in range(len(res)):
        res[i:i+1] = [res[i]]

# <END-OF-CODE>