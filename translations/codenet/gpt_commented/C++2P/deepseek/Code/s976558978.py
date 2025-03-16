# This section includes necessary headers and defines various constants and macros.
import sys

# File pointers for input and output
_fin = sys.stdin
_fout = sys.stdout

# Mathematical constants and limits
PI = 3.141592653589793238462643383279502884197169399375105820974
TEN5P1 = 100001
TEN6P1 = 1000001
TEN8P1 = 100000001
TEN9P1 = 1000000001

# Type definitions for convenience
uint = int
ll = int
ull = int

# Macros for loop iterations
def rep(var, n):
    for var in range(n):
        yield var

def repi(n):
    return rep(i, n)

def repj(n):
    return rep(j, n)

def repi1(n):
    for i in range(1, n):
        yield i

def repj1(n):
    for j in range(1, n):
        yield j

# Macros for min and max operations
def _min(a, b):
    return a if a < b else b

def _max(a, b):
    return a if a > b else b

# Macros for initializing arrays
def zeroi(data, n):
    for _ in range(n):
        data.append(0)

def zeroll(data, n):
    for _ in range(n):
        data.append(0)

def one(data, n):
    for _ in range(n):
        data.append(1)

# Functions for reading input
def readc():
    var = _fin.read(1)
    return var

def readi():
    var = int(_fin.readline().strip())
    return var

def readll():
    var = int(_fin.readline().strip())
    return var

# Function to read an array of integers
def repread(data, n):
    data.extend(map(int, _fin.readline().strip().split()))

# Function to read an array of long long integers
def repread(data, n):
    data.extend(map(int, _fin.readline().strip().split()))

# Function to read a string, ignoring empty lines
def reads(maxsize):
    str = _fin.readline().strip()
    if not str:
        return 0
    return str

# Macros for writing output
def writec(var):
    _fout.write(var)

def writecsp(var):
    _fout.write(var + " ")

def writecln(var):
    _fout.write(var + "\n")

def writei(var):
    _fout.write(str(var))

def writeisp(var):
    _fout.write(str(var) + " ")

def writellsp(var):
    _fout.write(str(var) + " ")

def writeiln(var):
    _fout.write(str(var) + "\n")

def writellln(var):
    _fout.write(str(var) + "\n")

def writeulln(var):
    _fout.write(str(var) + "\n")

def writefln(var):
    _fout.write(str(var) + "\n")

def writes(str):
    _fout.write(str)

def writesp():
    _fout.write(" ")

def writeln():
    _fout.write("\n")

# Macro to check if a number is even
def iseven(x):
    return 1 if x % 2 == 0 else 0

# Macro to run local tests with a specified input file
def RUN_LOCAL(testfilename):
    global _fin
    _fin = open(testfilename, "r")
    if not _fin:
        _fin = sys.stdin

# Macros for swapping values
def swap(type, a, b):
    t = a
    a = b
    b = t

def swapxor(a, b):
    a ^= b
    b ^= a
    a ^= b

# Macro for sorting an array
def sort(data):
    data.sort()

# Macro for modular arithmetic
def mod(a, b):
    return 0 if b == 0 else 0 if a == 0 else a % b if a > 0 else b + a % b

# Function to compute the greatest common divisor (GCD)
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

# Function to reverse an array of integers
def reversei(data, n):
    k = n // 2
    for i in range(k):
        data[i], data[n - i - 1] = data[n - i - 1], data[i]

# Function for binary search in a sorted array
def bsearch(val, data, n):
    if data[0] > val:
        return -1
    if data[n - 1] < val:
        return n
    l = 0
    r = n - 1
    while l < r:
        mid = (l + r + 1) // 2
        if data[mid] <= val:
            l = mid
        else:
            r = mid - 1
    if data[r] != val:
        r += 1
    return r

# Macro to define a dynamic array structure
class Vec:
    def __init__(self):
        self.data = []
        self.size = 0
        self.n = 0

    def init(self, size):
        self.data = [0] * size
        self.size = size
        self.n = 0

    def resize(self):
        self.size = int(self.size * 1.2)
        self.data = self.data + [0] * int(self.size * 0.2)

    def add(self, val):
        if self.n >= self.size:
            self.resize()
        self.data[self.n] = val
        self.n += 1

    def free(self):
        del self.data

# Define dynamic array structures for integers, long longs, and strings
Veci = Vec()
Vecll = Vec()
Vecs = Vec()

# Macro to check if two arrays are palindromes
def ispali(a, b, n):
    for i in range(n):
        if a[i] != b[n - i - 1]:
            return 0
    return 1

def ispalc(a, b, n):
    for i in range(n):
        if a[i] != b[n - i - 1]:
            return 0
    return 1

# Macro to define a pair structure and comparison functions
class Pair:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def cmp_Pair(a, b):
    if a.x == b.x:
        if a.y < b.y:
            return -1
        else:
            return 1
    if a.x < b.x:
        return -1
    else:
        return 1

def sort_Pair(d, n):
    d.sort(key=lambda x: (x.x, x.y))

# Function to compare strings for sorting
def cmp_Str(a, b):
    return -1 if a < b else 1 if a > b else 0

# Function to sort an array of strings
def sort_Str(str, n):
    str.sort(key=cmp_Str)

# Function to compute modular exponentiation
def expmod(x, n, m):
    ans = 1
    while n:
        if n & 1:
            ans = (ans * x) % m
        x = (x * x) % m
        n >>= 1
    return ans

# Function to compute combinations modulo m
def combmod(n, k, m):
    ret = 1
    div = 1
    for i in range(k):
        ret = (ret * (n - i)) % m
        div = (div * (i + 1)) % m
    div = expmod(div, m - 2, m)
    return (ret * div) % m

#------------

def main():
    # Run local test with specified input file
    RUN_LOCAL("dataabc155A.txt")

    # Read two integers from input
    a = readi()
    b = readi()

    # Output the smaller integer b times
    if a < b:
        for _ in range(b):
            writei(a)
        writeln()
    else:
        for _ in range(a):
            writei(b)
        writeln()

if __name__ == "__main__":
    main()
