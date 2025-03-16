
import bufio
import math
import os
import random
import sys
import time

abcd = "abcdefghijklmnopqrstuvwxyz"
ABCD = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
dx = [0, 1, 1, 1, 0, -1, -1, -1, 0]
dy = [1, 1, 0, -1, -1, -1, 0, 1, 0]
inf = float("inf")
mod = 1000000007
next = Scanner()

def init():
    global log
    log = logging.getLogger(__name__)
    log.setLevel(logging.DEBUG)
    log.addHandler(logging.StreamHandler())

def main():
    N = next.string()
    b = list(N)
    n = 0

    for i in range(len(b)):
        n += int(b[i] - '0')
    m, _ = strconv.Atoi(N)
    if m % n == 0:
        print("Yes")
    else:
        print("No")

class Pair:
    def __init__(self, a, b):
        self.a = a
        self.b = b

class Pairs(list):
    def __init__(self, *args):
        super().__init__(*args)

    def __lt__(self, other):
        return self.b < other.b

def in_range(c, a, z):
    return c >= a and c < z

def out_of_range(c, a, z):
    return not in_range(c, a, z)

def btoint(b):
    if b:
        return 1
    return 0

def itob(a):
    return a!= 0

def max_(*a):
    r = a[0]
    for i in range(len(a)):
        if r < a[i]:
            r = a[i]
    return r

def min_(*a):
    r = a[0]
    for i in range(len(a)):
        if r > a[i]:
            r = a[i]
    return r

def sum_(*a):
    r = 0
    for i in range(len(a)):
        r += a[i]
    return r

def pro_(*a):
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

def ceil(a, b):
    if a % b!= 0:
        return 1
    return 0

def print_strings(out):
    for i in range(len(out)):
        print(out[i], end=" ")
    print()

def print_ints(out):
    for i in range(len(out)):
        print(out[i], end=" ")
    print()

class Scanner:
    def __init__(self):
        self.r = bufio.BufferedReader(bufio. InputStreamReader(sys.stdin), 10000)
        self.buf = []
        self.p = 0

    def next(self):
        self.pre()
        start = self.p
        while self.p < len(self.buf) and self.buf[self.p]!= " ":
            self.p += 1
        result = "".join(self.buf[start:self.p])
        self.p += 1
        return result

    def line(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return "".join(self.buf[start:])

    def string(self):
        return self.next()

    def int(self):
        v = int(self.next())
        return v

    def ints(self, n):
        r = []
        for i in range(n):
            r.append(self.int())
        return r

    def int64(self):
        v = int(self.next())
        return v

    def uint64(self):
        v = int(self.next())
        return v

    def float64(self):
        v = float(self.next())
        return v

    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    def readLine(self):
        self.buf = []
        while True:
            l = self.r.readline()
            if not l:
                break
            self.buf.extend(l)

init()
main()

