
import bufio
import math
import os
import random
import sys
import time

# const abcd = "abcdefghijklmnopqrstuvwxyz"
# const ABCD = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
dx = [0, 1, 1, 1, 0, -1, -1, -1, 0]
dy = [1, 1, 0, -1, -1, -1, 0, 1, 0]

inf = float("inf")

# var mod = 1000000007
next = Scanner()

# ---------------------------------------------------------
# Initializes logging and random number generator seed
def init():
    global log
    log = logging.getLogger(__name__)
    log.setLevel(logging.DEBUG)
    log.addHandler(logging.StreamHandler())

    global rand
    rand.seed(time.time())

# Main function reads a string, calculates digit sum, and checks divisibility
def main():
    N = next.String() # Read input string
    b = list(N) # Convert string to byte slice
    n = 0 # Initialize sum of digits

    # Calculate sum of digits
    for i in range(len(b)):
        n += int(b[i])

    m = int(N) # Convert input string to integer
    if m % n == 0: # Check if the number is divisible by the sum of its digits
        print("Yes")
    else:
        print("No")

# ---------------------------------------------------------

# Pair is a struct representing a pair of integers
class Pair:
    def __init__(self, a, b):
        self.a = a
        self.b = b

# Pairs is a slice of Pair structs, implementing sort.Interface
class Pairs(list):
    def __init__(self, a):
        list.__init__(self, a)

    def Len(self):
        return len(self)

    def Swap(self, i, j):
        self[i], self[j] = self[j], self[i]

    def Less(self, i, j):
        return self[i].b < self[i].b

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
    return a!= 0

def max(*a):
    r = a[0]
    for i in range(len(a)):
        if r < a[i]:
            r = a[i]
    return r

def min(*a):
    r = a[0]
    for i in range(len(a)):
        if r > a[i]:
            r = a[i]
    return r

def sum(a):
    r = a[0]
    for i in range(1, len(a)):
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
    if a % b!= 0:
        return 1
    return 0

def printStrings(out):
    for i in range(len(out)):
        sys.stdout.write(str(out[i]))
        if i!= len(out) - 1:
            sys.stdout.write(" ")
    sys.stdout.write("\n")

def printInts(out):
    for i in range(len(out)):
        sys.stdout.write(str(out[i]))
        if i!= len(out) - 1:
            sys.stdout.write(" ")
    sys.stdout.write("\n")

# ---------- buffered scanner -----------------------------------------
class Scanner:
    def __init__(self):
        self.r = bufio.BufferedReader(bufio. InputStreamReader(sys.stdin), 10000)
        self.buf = []
        self.p = 0

    def next(self):
        self.pre()
        start = self.p
        while self.p < len(self.buf) and self.buf[self.p]!='':
            self.p += 1
        result = ''.join(self.buf[start:self.p])
        self.p += 1
        return result

    def Line(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return ''.join(self.buf[start:])

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
        while True:
            l = self.r.readline()
            if not l:
                break
            self.buf.extend(l)

init()
main()

