
# Python 3
# URL_HERE

# This section includes necessary headers and defines various constants and macros.
#ifdef _WIN32
#pragma warning(disable:4996) # Disable specific warnings for Windows
#endif
import sys
import math
import string
import collections
import itertools
import functools
import operator
import heapq
import array

# Mathematical constants and limits
PI = 3.141592653589793238462643383279502884197169399375105820974
ten5p1 = 100001
ten6p1 = 1000001
ten8p1 = 100000001
ten9p1 = 1000000001

# Type definitions for convenience
uint = int
ll = int
ull = int

# Macros for loop iterations
def rep(var,n):
    for var in range(n):
        yield var
def repi(n):
    for i in range(n):
        yield i
def repj(n):
    for j in range(n):
        yield j
def repi1(n):
    for i in range(1,n):
        yield i
def repj1(n):
    for j in range(1,n):
        yield j

# Macros for min and max operations
def _min(a,b):
    return a if a<b else b
def _max(a,b):
    return a if a>b else b

# Macros for initializing arrays
def zeroi(data,n):
    data.clear()
    data.extend([0]*n)
def zeroll(data,n):
    data.clear()
    data.extend([0]*n)
def one(data,n):
    data.clear()
    data.extend([1]*n)

# Functions for reading input
def readc():
    return sys.stdin.read(1)
def readi():
    return int(sys.stdin.readline())
def readll():
    return int(sys.stdin.readline())

# Function to read an array of integers
def repread(data,n):
    for i in range(n):
        data.append(readi())

# Function to read an array of long long integers
def repread(data,n):
    for i in range(n):
        data.append(readll())

# Function to read a string, ignoring empty lines
def reads(str, maxsize):
    for str in sys.stdin:
        if str[0]!= '\n' and str[0]!= '\r':
            break
    return str

# Macros for writing output
def writec(var):
    sys.stdout.write(var)
def writecsp(var):
    sys.stdout.write(var +'')
def writecln(var):
    sys.stdout.write(var + '\n')
def writei(var):
    sys.stdout.write(str(var))
def writeisp(var):
    sys.stdout.write(str(var) +'')
def writellsp(var):
    sys.stdout.write(str(var) +'')
def writeiln(var):
    sys.stdout.write(str(var) + '\n')
def writellln(var):
    sys.stdout.write(str(var) + '\n')
def writeulln(var):
    sys.stdout.write(str(var) + '\n')
def writefln(var):
    sys.stdout.write(str(var) + '\n')
def writes(str):
    sys.stdout.write(str)
def writesp():
    sys.stdout.write(' ')
def writeln():
    sys.stdout.write('\n')

# Macro to check if a number is even
def iseven(x):
    return (x&1)==0

# Macro to run local tests with a specified input file
def RUN_LOCAL(testfilename):
    sys.stdin = open(testfilename, "r")

# Macros for swapping values
def swap(type,a, b):
    t = a
    a = b
    b = t
def swapxor(a,b):
    a ^= b
    b ^= a
    a ^= b

# Macro for sorting an array
def sort(data,n):
    data.sort()

# Macro for modular arithmetic
def mod(a,b):
    return b==0? 0 : a==0? 0 :(a>0? a%b : b + a % b)

# Function to compute the greatest common divisor (GCD)
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

# Function to reverse an array of integers
def reversei(data,n):
    k = n >> 1
    for i in range(k):
        tmp = data[i]
        data[i] = data[n - i - 1]
        data[n - i - 1] = tmp

# Function for binary search in a sorted array
def bsearch(val, data, n):
    if data[0] > val:
        return -1
    if data[n - 1] < val:
        return n
    l = 0
    r = n - 1
    while l < r:
        mid = (l + r + 1) >> 1
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
            self.data = [None] * size
            self.size = size
            self.n = 0
        def resize(self):
            ns = self.size * 1.2
            self.data = self.data + [None] * (ns - self.size)
            self.size = ns
        def add(self, val):
            if self.n >= self.size:
                self.resize()
            k = self.n
            self.data[k] = val
            self.n = k + 1
        def free(self):
            self.data = None
    return name

# Define dynamic array structures for integers, long longs, and strings
Veci = _Vec(int, 'Veci')
Vecll = _Vec(int, 'Vecll')
Vecs = _Vec(str, 'Vecs')

# Macro to check if two arrays are palindromes
def _ispal(type, name):
    def ispali(a, b, n):
        for i in range(n):
            if a[i]!= b[n - i - 1]:
                return 0
        return 1
    return ispali
ispali = _ispal(int, 'ispali')
ispalc = _ispal(str, 'ispalc')

# Macro to define a pair structure and comparison functions
def _Pair(type, name):
    class name:
        def __init__(self, x, y):
            self.x = x
            self.y = y
    def cmp(a, b):
        if a.x == b.x:
            if a.y < b.y:
                return -1
            else:
                return 1
        if a.x < b.x:
            return -1
        else:
            return 1
    def sort(d, n):
        d.sort(key=functools.cmp_to_key(cmp))
    return name, cmp, sort
Pairi, cmp_Pairi, sort_Pairi = _Pair(int, 'Pairi')

# Function to compare strings for sorting
def cmp_Str(a, b):
    return cmp(a, b)

# Function to sort an array of strings
def sort_Str(str, n):
    str.sort()

# Function to compute modular exponentiation
def expmod(x, n, m):
    ans = 1
    for n in range(n):
        if n & 1:
            ans = (ans * x) % m
        x = (x * x) % m
    return ans

# Function to compute combinations modulo m
def combmod(n, k, m):
    ret = 1
    div = 1
    for i in range(k):
        ret = (ret * (n - i) % m) % m
        div = (div * (i + 1)) % m
    div = expmod(div, m - 2, m) % m
    return (ret * div) % m

#------------

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

# 