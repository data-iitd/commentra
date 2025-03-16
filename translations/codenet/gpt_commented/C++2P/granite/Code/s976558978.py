
# URL_HERE

# File pointers for input and output
_fin = open("dataabc155A.txt", "r") if "dataabc155A.txt" else sys.stdin
_fout = sys.stdout

# Mathematical constants and limits
PI = 3.141592653589793238462643383279502884197169399375105820974
ten5p1 = 100001
ten6p1 = 1000001
ten8p1 = 100000001
ten9p1 = 10000000001

# Type definitions for convenience
uint = int
ll = int
ull = int

# Macros for loop iterations
def rep(var, n):
    for var in range(n):
        pass

def repi(n):
    rep(i, n)

def repj(n):
    rep(j, n)

def repi1(n):
    for i in range(1, n):
        pass

def repj1(n):
    for j in range(1, n):
        pass

# Macros for min and max operations
def _min(a, b):
    return a if a < b else b

def _max(a, b):
    return a if a > b else b

# Macros for initializing arrays
def zeroi(data, n):
    data = [0] * n

def zeroll(data, n):
    data = [0] * n

def one(data, n):
    for i in range(n):
        data[i] = 1

# Functions for reading input
def readc():
    return _fin.read(1)

def readi():
    return int(_fin.readline())

def readll():
    return int(_fin.readline())

# Function to read an array of integers
def repread(data, n):
    for i in range(n):
        data[i] = readi()

# Function to read an array of long long integers
def repread(data, n):
    for i in range(n):
        data[i] = readll()

# Function to read a string, ignoring empty lines
def reads(str, maxsize):
    line = _fin.readline()
    while line == "\n" or line == "\r\n":
        line = _fin.readline()
    slen = len(line)
    if slen == 0:
        return 0
    if line[-1] == "\n" or line[-1] == "\r":
        line = line[:-1]
    return line

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
    return (x & 1) == 0

# Macro to run local tests with a specified input file
def RUN_LOCAL(testfilename):
    global _fin
    _fin = open(testfilename, "r") if testfilename else sys.stdin

# Macros for swapping values
def swap(type, a, b):
    temp = a
    a = b
    b = temp

def swapxor(a, b):
    a ^= b
    b ^= a
    a ^= b

# Macro for sorting an array
def sort(data, n):
    data.sort()

# Macro for modular arithmetic
def mod(a, b):
    return b if b == 0 else a if a == 0 else (a if a > 0 else b + a % b)

# Function to compute the greatest common divisor (GCD)
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

# Function to reverse an array of integers
def reversei(data, n):
    for i in range(n // 2):
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
    if data[r]!= val:
        r += 1
    return r

# Macro to define a dynamic array structure
def _Vec(type, name):
    class name:
        def __init__(self, size):
            self.data = [0] * size
            self.size = size
            self.n = 0

        def resize(self):
            self.size *= 1.2
            self.data = [0] * self.size

        def add(self, val):
            if self.n >= self.size:
                self.resize()
            self.data[self.n] = val
            self.n += 1

        def free(self):
            del self.data

# Define dynamic array structures for integers, long longs, and strings
_Vec(int, Veci)
_Vec(ll, Vecll)
_Vec(char*, Vecs)

# Macro to check if two arrays are palindromes
def _ispal(type, name):
    def name(a, b, n):
        for i in range(n):
            if a[i]!= b[n - i - 1]:
                return 0
        return 1

_ispal(int, ispali)
_ispal(char, ispalc)

# Macro to define a pair structure and comparison functions
def _Pair(type, name):
    class name:
        def __init__(self, x, y):
            self.x = x
            self.y = y

    def cmp_name(a, b):
        if a.x == b.x:
            if a.y < b.y:
                return -1
            else:
                return 1
        if a.x < b.x:
            return -1
        else:
            return 1

    def sort_name(d, n):
        d.sort(key=cmp_to_key(cmp_name))

_Pair(int, Pairi)

# Function to compute modular exponentiation
def expmod(x, n, m):
    ans = 1
    for i in range(n):
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

if __name__ == "__main__":
    RUN_LOCAL("dataabc155A.txt")
    a = readi()
    b = readi()
    if a < b:
        for i in range(b):
            writei(a)
        writeln()
    else:
        for i in range(a):
            writei(b)
        writeln()

