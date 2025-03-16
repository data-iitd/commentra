
import sys
import bufio

# const abcd = "abcdefghijklnmopqrstuvwxyz"
# const ABCD = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

# var dy = [...]int{1, 1, 0, -1, -1, -1, 0, 1}
# var dx = [...]int{0, 1, 1, 1, 0, -1, -1, -1}

inf = 1e14

# var mod = 1000000007

# ---------------------------------------------------------
def main():
    next = Scanner()
    n = next.Int()
    x = next.Int()
    a = [next.Int() for _ in range(n)]
    v = a[:]
    ans = inf
    for k in range(n):
        kans = 0
        for i in range(n):
            if i-k < 0:
                v[i] = min(v[i], a[n+i-k])
            else:
                v[i] = min(v[i], a[i-k])
            kans += v[i]
        ans = min(ans, kans+k*x)

    print(ans)

# ---------------------------------------------------------

# Pair is liked C++ pair
class Pair:
    def __init__(self, a, b):
        self.a = a
        self.b = b

# Pairs is sorted by []Pair struct
class Pairs(list):
    def __init__(self, *args):
        super().__init__(*args)

    def __lt__(self, other):
        if self.a < other.a:
            return True
        elif self.a == other.a:
            return self.b < other.b
        return False

# -------------------------------
def in(c, a, z):
    return c >= a and c < z

def btoi(b):
    if b:
        return 1
    return 0

def itob(a):
    if a == 0:
        return False
    return True

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

def minmax(a, b):
    if a > b:
        return b, a
    return a, b

def abs(a):
    if a < 0:
        return -a
    return a

def sum(*a):
    r = a[0]
    if len(a) > 1:
        for i in range(1, len(a)):
            r += a[i]
    return r

# ---------- buffered scanner -----------------------------------------
class Scanner:
    def __init__(self):
        self.r = bufio.BufferedReader(sys.stdin, 10000)
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

    def Int(self):
        return int(self.next())

    def Int64(self):
        return int(self.next())

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

# </END-OF-CODE>
