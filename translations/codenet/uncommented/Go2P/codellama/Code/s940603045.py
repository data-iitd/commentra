
import sys
import math
import string
import itertools

# const abcd = "abcdefghijklmnopqrstuvwxyz"
# const ABCD = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
dx = [0, 1, 1, 1, 0, -1, -1, -1, 0]
dy = [1, 1, 0, -1, -1, -1, 0, 1, 0]

# var mod = 1000000007

# ---------------------------------------------------------

# def init():
#     log.SetFlags(log.Lshortfile)
#     rand.Seed(time.Now().UnixNano())

def main():
    N = sys.stdin.readline().strip()
    b = list(N)
    n = 0

    for i in range(len(b)):
        n += int(b[i])
    m = int(N)
    if m % n == 0:
        print("Yes")
    else:
        print("No")

# ---------------------------------------------------------

# Pair is...
class Pair:
    def __init__(self, a, b):
        self.a = a
        self.b = b

# Pairs is sorted by []Pair struct
class Pairs(list):
    def __lt__(self, other):
        return self.b < other.b

# ------int method-------------------------
def in(c, a, z):
    return c >= a and c < z

def out(c, a, z):
    return not in(c, a, z)

def btoi(b):
    if b:
        return 1
    return 0

def itob(a):
    return a != 0

def max(a):
    r = a[0]
    for i in range(len(a)):
        if r < a[i]:
            r = a[i]
    return r

def min(a):
    r = a[0]
    for i in range(len(a)):
        if r > a[i]:
            r = a[i]
    return r

def sum(a):
    r = 0
    for i in range(len(a)):
        r += a[i]
    return r

def pro(a):
    r = a[0]
    for i in range(1, len(a)):
        r *= a[i]
    return r

def fill(a, n):
    for i in range(len(a)):
        a[i] = n
    return a

def minmax(a, b):
    if a > b:
        return b, a
    return a, b

def abs(a):
    if a < 0:
        return -a
    return a

#
#def abs(a):
#    mask = a >> 63
#    return (a ^ mask) - mask

def ceil(a, b):
    if a % b != 0:
        return 1
    return 0

def printStrings(out):
    for i in range(len(out)):
        print(out[i], end=" ")
    print()

def printInts(out):
    for i in range(len(out)):
        print(out[i], end=" ")
    print()

# ---------- buffered scanner -----------------------------------------
class scanner:
    def __init__(self):
        self.r = sys.stdin
        self.buf = []
        self.p = 0

    def next(self):
        self.pre()
        start = self.p
        for ; self.p < len(self.buf); self.p++:
            if self.buf[self.p] == ' ':
                break
        result = "".join(self.buf[start:self.p])
        self.p++
        return result

    def Line(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return "".join(self.buf[start:])

    def String(self):
        return self.next()

    def Int(self):
        v = int(self.next())
        return v

    def Ints(self, n):
        r = []
        for i in range(n):
            r.append(self.Int())
        return r

    def Int64(self):
        v = int(self.next())
        return v

    def Uint64(self):
        v = int(self.next())
        return v

    def Float64(self):
        v = float(self.next())
        return v

    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    def readLine(self):
        self.buf = []
        for ; ; :
            l, p, err = self.r.readline()
            if err != None:
                log.Fatal(err)
            self.buf.extend(l)
            if not p:
                break

# ---------------------------------------------------------

# def init():
#     log.SetFlags(log.Lshortfile)
#     rand.Seed(time.Now().UnixNano())

# def main():
#     N = sys.stdin.readline().strip()
#     b = list(N)
#     n = 0

#     for i in range(len(b)):
#         n += int(b[i])
#     m = int(N)
#     if m % n == 0:
#         print("Yes")
#     else:
#         print("No")

# ---------------------------------------------------------

# Pair is...
# class Pair:
#     def __init__(self, a, b):
#         self.a = a
#         self.b = b

# # Pairs is sorted by []Pair struct
# class Pairs(list):
#     def __lt__(self, other):
#         return self.b < other.b

# ------int method-------------------------
# def in(c, a, z):
#     return c >= a and c < z

# def out(c, a, z):
#     return not in(c, a, z)

# def btoi(b):
#     if b:
#         return 1
#     return 0

# def itob(a):
#     return a != 0

# def max(a):
#     r = a[0]
#     for i in range(len(a)):
#         if r < a[i]:
#             r = a[i]
#     return r

# def min(a):
#     r = a[0]
#     for i in range(len(a)):
#         if r > a[i]:
#             r = a[i]
#     return r

# def sum(a):
#     r = 0
#     for i in range(len(a)):
#         r += a[i]
#     return r

# def pro(a):
#     r = a[0]
#     for i in range(1, len(a)):
#         r *= a[i]
#     return r

# def fill(a, n):
#     for i in range(len(a)):
#         a[i] = n
#     return a

# def minmax(a, b):
#     if a > b:
#         return b, a
#     return a, b

# def abs(a):
#     if a < 0:
#         return -a
#     return a

# #
# def abs(a):
#     mask = a >> 63
#     return (a ^ mask) - mask

# def ceil(a, b):
#     if a % b != 0:
#         return 1
#     return 0

# def printStrings(out):
#     for i in range(len(out)):
#         print(out[i], end=" ")
#     print()

# def printInts(out):
#     for i in range(len(out)):
#         print(out[i], end=" ")
#     print()

# # ---------- buffered scanner -----------------------------------------
# class scanner:
#     def __init__(self):
#         self.r = sys.stdin
#         self.buf = []
#         self.p = 0

#     def next(self):
#         self.pre()
#         start = self.p
#         for ; self.p < len(self.buf); self.p++:
#             if self.buf[self.p] == ' ':
#                 break
#         result = "".join(self.buf[start:self.p])
#         self.p++
#         return result

#     def Line(self):
#         self.pre()
#         start = self.p
#         self.p = len(self.buf)
#         return "".join(self.buf[start:])

#     def String(self):
#         return self.next()

#     def Int(self):
#         v = int(self.next())
#         return v

#     def Ints(self, n):
#         r = []
#         for i in range(n):
#             r.append(self.Int())
#         return r

#     def Int64(self):
#         v = int(self.next())
#         return v

#     def Uint64(self):
#         v = int(self.next())
#         return v

#     def Float64(self):
#         v = float(self.next())
#         return v

#     def pre(self):
#         if self.p >= len(self.buf):
#             self.readLine()
#             self.p = 0

#     def readLine(self):
#         self.buf = []
#         for ; ; :
#             l, p, err = self.r.readline()
#             if err != None:
#                 log.Fatal(err)
#             self.buf.extend(l)
#             if not p:
#                 break

# ---------------------------------------------------------

# def init():
#     log.SetFlags(log.Lshortfile)
#     rand.Seed(time.Now().UnixNano())

# def main():
#     N = sys.stdin.readline().strip()
#     b = list(N)
#     n = 0

#     for i in range(len(b)):
#         n += int(b[i])
#     m = int(N)
#     if m % n == 0:
#         print("Yes")
#     else:
#         print("No")

# ---------------------------------------------------------

# Pair is...
# class Pair:
#     def __init__(self, a, b):
#         self.a = a
#         self.b = b

# # Pairs is sorted by []Pair struct
# class Pairs(list):
#     def __lt__(self, other):
#         return self.b < other.b

# ------int method-------------------------
# def in(c, a, z):
#     return c >= a and c < z

# def out(c, a, z):
#     return not in(c, a, z)

# def btoi(b):
#     if b:
#         return 1
#     return 0

# def itob(a):
#     return a != 0

# def max(a):
#     r = a[0]
#     for i in range(len(a)):
#         if r < a[i]:
#             r = a[i]
#     return r

# def min(a):
#     r = a[0]
#     for i in range(len(a)):
#         if r > a[i]:
#             r = a[i]
#     return r

# def sum(a):
#     r = 0
#     for i in range(len(a)):
#         r += a[i]
#     return r

# def pro(a):
#     r = a[0]
#     for i in range(1, len(a)):
#         r *= a[i]
#     return r

# def fill(a, n):
#     for i in range(len(a)):
#         a[i] = n
#     return a

# def minmax(a, b):
#     if a > b:
#         return b, a
#     return a, b

# def abs(a):
#     if a < 0:
#         return -a
#     return a

# #
# def abs(a):
#     mask = a >> 63
#     return (a ^ mask) - mask

# def ceil(a, b):
#     if a % b != 0:
#         return 1
#     return 0

# def printStrings(out):
#     for i in range(len(out)):
#         print(out[i], end=" ")
#     print()

# def printInts(out):
#     for i in range(len(out)):
#         print(out[i], end=" ")
#     print()

# # ---------- buffered scanner -----------------------------------------
# class scanner:
#     def __init__(self):
#         self.r = sys.stdin
#         self.buf = []
#         self.p = 0

#     def next(self):
#         self.pre()
#         start = self.p
#         for ; self.p < len(self.buf); self.p++:
#             if self.buf[self.p] == ' ':
#                 break
#         result = "".join(self.buf[start:self.p])
#         self.p++
#         return result

#     def Line(self):
#         self.pre()
#         start = self.p
#         self.p = len(self.buf)
#         return "".join(self.buf[start:])

#     def String(self):
#         return self.next()

#     def Int(self):
#         v = int(self.next())
#         return v

#     def Ints(self, n):
#         r = []
#         for i in range(n):
#             r.append(self.Int())
#         return r

#     def Int64(self):
#         v = int(self.next())
#         return v

#     def Uint64(self):
#         v = int(self.next())
#         return v

#     def Float64(self):
#         v = float(self.next())
#         return v

#     def pre(self):
#         if self.p >= len(self.buf):
#             self.readLine()
#             self.p = 0

#     def readLine(self):
#         self.buf = []
#         for ; ; :
#             l, p, err = se