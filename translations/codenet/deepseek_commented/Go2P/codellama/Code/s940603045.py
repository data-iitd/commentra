
import sys
import math
import string
import random

# const abcd = "abcdefghijklmnopqrstuvwxyz"
# const ABCD = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
dx = [0, 1, 1, 1, 0, -1, -1, -1, 0]
dy = [1, 1, 0, -1, -1, -1, 0, 1, 0]

# var mod = 1000000007
next = Scanner()

# ---------------------------------------------------------
# Initializes logging and random number generator seed
def init():
    log.basicConfig(level=log.Lshortfile)
    random.seed(time.time())

# Main function reads a string, calculates digit sum, and checks divisibility
def main():
    N = next.String() # Read input string
    b = list(N)       # Convert string to byte slice
    n = 0             # Initialize sum of digits

    # Calculate sum of digits
    for i in range(len(b)):
        n += int(b[i]) - ord('0')
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
class Pairs:
    def __init__(self, pairs):
        self.pairs = pairs

    def Len(self):
        return len(self.pairs)

    def Swap(self, i, j):
        self.pairs[i], self.pairs[j] = self.pairs[j], self.pairs[i]

    def Less(self, i, j):
        return self.pairs[i].b < self.pairs[i].b

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
        print(out[i])
        if i != len(out) - 1:
            print(" ")
    print("\n")

def printInts(out):
    for i in range(len(out)):
        print(out[i])
        if i != len(out) - 1:
            print(" ")
    print("\n")

# ---------- buffered scanner -----------------------------------------
class Scanner:
    def __init__(self):
        self.r = bufio.Reader(sys.stdin, 10000)
        self.buf = []
        self.p = 0

    def next(self):
        self.pre()
        start = self.p
        for ; self.p < len(self.buf); self.p++:
            if self.buf[self.p] == ' ':
                break
        result = string.join(self.buf[start:self.p])
        self.p++
        return result

    def Line(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return string.join(self.buf[start:])

    def String(self):
        return self.next()

    def Int(self):
        v, err = strconv.Atoi(self.next())
        if err != nil:
            log.Fatal(err)
        return v

    def Ints(self, n):
        r = []
        for i in range(n):
            r.append(self.Int())
        return r

    def Int64(self):
        v, err = strconv.ParseInt(self.next(), 10, 64)
        if err != nil:
            log.Fatal(err)
        return v

    def Uint64(self):
        v, err = strconv.ParseUint(self.next(), 10, 64)
        if err != nil:
            log.Fatal(err)
        return v

    def Float64(self):
        v, err = strconv.ParseFloat(self.next(), 64)
        if err != nil:
            log.Fatal(err)
        return v

    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    def readLine(self):
        self.buf = []
        for ; ; :
            l, p, err = self.r.ReadLine()
            if err != nil:
                log.Fatal(err)
            self.buf.append(l)
            if not p:
                break

# ---------------------------------------------------------
# Initializes logging and random number generator seed
init()

# Main function reads a string, calculates digit sum, and checks divisibility
main()

