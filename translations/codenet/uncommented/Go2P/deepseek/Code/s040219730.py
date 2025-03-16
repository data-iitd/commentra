import sys
import os
import math
import bisect
import collections
from operator import itemgetter
from itertools import product
from functools import reduce
from heapq import heappush, heappop
from io import StringIO
import string

# fmt.Sprintf("%b\n", 255) 	# binary expression

#str := ReadString()
#i := ReadInt()
#X := ReadIntSlice(n)
#S := ReadRuneSlice()
#a := ReadFloat64()
#A := ReadFloat64Slice(n)

#str := ZeroPaddingRuneSlice(num, 32)
#str := PrintIntsLine(X...)

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

def init():
    global ReadString
    global stdout
    ReadString = new_read_string(sys.stdin.readline, lambda: sys.stdin.readline().split())
    stdout = sys.stdout

def new_read_string(read_func, split_func):
    def _wrapper(*args, **kwargs):
        return next(iter(read_func(*args, **kwargs)))
    return _wrapper

def ReadInt():
    return int(ReadString())

def ReadInt2():
    return int(ReadString()), int(ReadString())

def ReadInt3():
    return int(ReadString()), int(ReadString()), int(ReadString())

def ReadInt4():
    return int(ReadString()), int(ReadString()), int(ReadString()), int(ReadString())

def ReadInt64():
    return int(ReadString())

def ReadInt64_2():
    return int(ReadString()), int(ReadString())

def ReadInt64_3():
    return int(ReadString()), int(ReadString()), int(ReadString())

def ReadInt64_4():
    return int(ReadString()), int(ReadString()), int(ReadString()), int(ReadString())

def read_int64():
    return int(ReadString())

def ReadIntSlice(n):
    return [ReadInt() for _ in range(n)]

def ReadInt64Slice(n):
    return [ReadInt64() for _ in range(n)]

def ReadFloat64():
    return float(ReadString())

def read_float64():
    return float(ReadString())

def ReadFloat64Slice(n):
    return [ReadFloat64() for _ in range(n)]

def ReadRuneSlice():
    return list(ReadString())

def ZeroPaddingRuneSlice(n, digits_num):
    sn = format(n, 'b')
    residual_length = digits_num - len(sn)
    if residual_length <= 0:
        return list(sn)
    zeros = ['0'] * residual_length
    return zeros + list(sn)

def Strtoi(s):
    return int(s)

def PrintIntsLine(A):
    return ' '.join(map(str, A))

def PrintInts64Line(A):
    return ' '.join(map(str, A))

def PrintfDebug(format, *args):
    print(format % args, file=sys.stderr)

def PrintfBufStdout(format, *args):
    print(format % args, file=stdout)

class FenwickTree:
    def __init__(self, n):
        self.dat = [0] * (n + 1)
        self.n = n
        self.min_pow2 = 1
        while (self.min_pow2 << 1) <= n:
            self.min_pow2 <<= 1

    def Sum(self, i):
        s = 0
        while i > 0:
            s += self.dat[i]
            i -= i & -i
        return s

    def Add(self, i, x):
        while i <= self.n:
            self.dat[i] += x
            i += i & -i

    def LowerBound(self, w):
        if w <= 0:
            return 0
        x = 0
        for k in range(self.min_pow2, 0, -1):
            if x + k <= self.n and self.dat[x + k] < w:
                w -= self.dat[x + k]
                x += k
        return x + 1

init()

n, q = ReadInt2()
C = ReadIntSlice(n)

P = [-1] * (500000 + 50)
Answers = [0] * (500000 + 50)

Q = []
for _ in range(q):
    l, r = ReadInt2()
    Q.append((_, l, r))

Q.sort(key=itemgetter(2))
ft = FenwickTree(500000 + 50)

k = 0
for _, l, r in Q:
    while k < r:
        if P[C[k]] != -1:
            ft.Add(P[C[k]] + 1, -1)
        P[C[k]] = k
        ft.Add(k + 1, 1)
        k += 1

    Answers[_] = ft.Sum(r) - ft.Sum(l - 1)

for i in range(q):
    PrintfBufStdout("%d\n", Answers[i])
