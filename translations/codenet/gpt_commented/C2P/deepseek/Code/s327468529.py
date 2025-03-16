# Suppress warnings for incompatible pointer types
# Include necessary headers
import sys
import math
from collections import deque
from collections import defaultdict

# Define constants for large numbers and modular arithmetic
BIG = 2000000007
VERYBIG = 20000000000000007
MOD = 1000000007
FOD = 998244353

# Define types for unsigned and signed long long integers
ull = int
sll = int

# Define maximum size for arrays
N_MAX = 1048576

# Include C++ standard library headers if compiling as C++
try:
    from queue import Queue
    from queue import LifoQueue
    from queue import PriorityQueue
    from collections import namedtuple
    from collections import OrderedDict
    from collections import Counter
    from itertools import permutations
    from itertools import combinations
    from itertools import product
    import heapq
    import functools
    import operator
    import string
    import array
except ImportError:
    pass

# Define M_PI if not already defined
M_PI = 3.14159265358979323846264338327950

# Define structures for various data types
hwll = namedtuple('hwll', ['a', 'b'])
hwllc = namedtuple('hwllc', ['a', 'b', 'c'])
linell = namedtuple('linell', ['a', 'b'])
hwreal = namedtuple('hwreal', ['a', 'b'])

# Global variables for various parameters
n, m = 0, 0
h, w = 0, 0
k = 0
q = 0
va, vb, vc, vd, ve, vf = 0, 0, 0, 0, 0, 0
ua, ub, uc, ud, ue, uf = 0, 0, 0, 0, 0, 0
vra, vrb, vrc = 0.0, 0.0, 0.0
vda, vdb, vdc = 0.0, 0.0, 0.0
ch, dh = '', ''

# Function to return the minimum of two unsigned long long integers
def umin(x, y):
    return x if x < y else y

# Function to return the maximum of two unsigned long long integers
def umax(x, y):
    return x if x > y else y

# Function to return the minimum of two signed long long integers
def smin(x, y):
    return x if x < y else y

# Function to return the maximum of two signed long long integers
def smax(x, y):
    return x if x > y else y

# Function to compute the greatest common divisor (GCD) of two unsigned long long integers
def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

# Function to compute a^x mod modulo using binary exponentiation
def bitpow(a, x, modulo):
    result = 1
    while x:
        if x & 1:
            result = (result * a) % modulo
        a = (a * a) % modulo
        x >>= 1
    return result

# Function to perform modular division a / b mod modulo
def divide(a, b, modulo):
    return (a * bitpow(b, modulo - 2, modulo)) % modulo

# Function to return the absolute difference between two unsigned long long integers
def udiff(a, b):
    return a - b if a >= b else b - a

# Function to return the absolute difference between two signed long long integers
def sdiff(a, b):
    return a - b if a >= b else b - a

# Function to count the number of set bits in an unsigned long long integer
def bitcount(n):
    result = 0
    while n:
        result += n & 1
        n >>= 1
    return result

# Macros for comparison functions
def BEGCMP(NAME):
    def NAME(left, right):
        l = left
        r = right
        if l < r:
            return -1
        if l > r:
            return 1
        return 0

# Comparison function for unsigned long long integers
pullcomp = BEGCMP(pullcomp)

# Comparison function for signed long long integers in reverse order
prevcomp = BEGCMP(prevcomp)

# Comparison function for signed long long integers
psllcomp = BEGCMP(psllcomp)

# Comparison function for characters
pcharcomp = BEGCMP(pcharcomp)

# Comparison function for double values
pdoublecomp = BEGCMP(pdoublecomp)

# Comparison function for strings
def pstrcomp(left, right):
    l = left
    r = right
    return cmp(l, r)

# Comparison function for hwll structures based on fields a and b
def phwllABcomp(left, right):
    l = left
    r = right
    if l.a < r.a:
        return -1
    if l.a > r.a:
        return 1
    if l.b < r.b:
        return -1
    if l.b > r.b:
        return 1
    return 0

# Comparison function for hwll structures in reverse order
def phwllREVcomp(left, right):
    l = left
    r = right
    if l.b < r.b:
        return -1
    if l.b > r.b:
        return 1
    if l.a < r.a:
        return -1
    if l.a > r.a:
        return 1
    return 0

# Comparison function for hwllc structures based on fields a, b, and c
def ptriplecomp(left, right):
    l = left
    r = right
    if l.a < r.a:
        return -1
    if l.a > r.a:
        return 1
    if l.b < r.b:
        return -1
    if l.b > r.b:
        return 1
    if l.c < r.c:
        return -1
    if l.c > r.c:
        return 1
    return 0

# Comparison function for hwllc structures in reverse order
def ptripleREVcomp(left, right):
    l = left
    r = right
    if l.b < r.b:
        return -1
    if l.b > r.b:
        return 1
    if l.a < r.a:
        return -1
    if l.a > r.a:
        return 1
    if l.c < r.c:
        return -1
    if l.c > r.c:
        return 1
    return 0

# Comparison function for hwllc structures based on field c, then a, then b
def ptripleCABcomp(left, right):
    l = left
    r = right
    if l.c < r.c:
        return -1
    if l.c > r.c:
        return 1
    if l.a < r.a:
        return -1
    if l.a > r.a:
        return 1
    if l.b < r.b:
        return -1
    if l.b > r.b:
        return 1
    return 0

# Comparison function for hwreal structures based on fields a and b
def phwrealcomp(left, right):
    l = left
    r = right
    if l.a < r.a:
        return -1
    if l.a > r.a:
        return 1
    if l.b < r.b:
        return -1
    if l.b > r.b:
        return 1
    return 0

# Comparison function for linell structures based on their components
def pquadcomp(left, right):
    l = left
    r = right
    ac = phwllABcomp(l.a, r.a)
    if ac != 0:
        return ac
    bc = phwllABcomp(l.b, r.b)
    if bc != 0:
        return bc
    return 0

# Comparison function for hwllc structures based on a fraction
def pfracomp(left, right):
    l = left
    r = right
    return sdiff(l.a * r.b, l.b * r.a)

# Function to check if a value x is within a range [left, right]
def isinrange(left, x, right):
    return left <= x <= right

# Function to check if a value x is within a range [left, right] or vice versa
def isinrange_soft(left, x, right):
    return (left <= x <= right) or (left >= x >= right)

# Function to swap two signed long long integers
def sw(l, r):
    if l == r:
        return
    l, r = r, l

# Arrays for factorials and their inverses
frac = [0] * (N_MAX * 3)
invf = [0] * (N_MAX * 3)

# Function to compute n choose r modulo m
def ncr(n, r, m):
    if n < 0 or r < 0 or n < r:
        return 0
    return frac[n] * (invf[r] * invf[n - r] % m) % m

# Arrays for various data types
a = [0] * (N_MAX + 5)
b = [0] * (N_MAX + 5)
c = [0] * (N_MAX + 5)
d = [0] * (N_MAX + 5)
e = [0] * (N_MAX * 4)
s = ''
t = ''
u = ''
xy = [hwll(0, 0)] * (N_MAX + 5)
tup = [hwllc(0, 0, 0)] * (N_MAX + 5)
table = [[0] * 3005 for _ in range(3005)]
gin = [0] * N_MAX

# Initialize counters and arrays for computations
cnt = [0] * 3
pcnt = 0
x = [[0] * 3005 for _ in range(3005)]

# Main solving function
def solve():
    i, j, ki, li = 0, 0, 0, 0
    result = 0
    maybe = 0
    sum = 0
    item = 0
    dpcell = None

    result = 1

    for i in range(n * 3):
        v = 0
        if s[i] == 'R':
            v = 0
        elif s[i] == 'G':
            v = 1
        elif s[i] == 'B':
            v = 2

        if cnt[(v + 1) % 3] and cnt[(v + 2) % 3]:
            result *= pcnt
            result %= FOD
            cnt[(v + 1) % 3] -= 1
            cnt[(v + 2) % 3] -= 1
            pcnt -= 1
        else:
            if (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]:
                result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v]
                result %= FOD
                pcnt += 1
            cnt[v] += 1

    result = (result * math.factorial(n)) % FOD

    print(result)
    return 0

# Main function to execute the program
if __name__ == "__main__":
    n = 4
    m = 0

    # Read input values
    n, m = map(int, sys.stdin.readline().split())
    s = sys.stdin.readline().strip()

    # Call the solve function to compute the result
    solve()
