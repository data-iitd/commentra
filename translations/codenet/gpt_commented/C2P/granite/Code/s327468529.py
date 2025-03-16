
import sys

# Define constants for large numbers and modular arithmetic
BIG = 2000000007
VERYBIG = 20000000000000007LL
MOD = 1000000007
FOD =  998244353

# Define maximum size for arrays
N_MAX = 1048576

# Define structures for various data types
class hwll:
    def __init__(self, a, b):
        self.a = a
        self.b = b

class hwllc:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

class linell:
    def __init__(self, a, b):
        self.a = a
        self.b = b

class hwreal:
    def __init__(self, a, b):
        self.a = a
        self.b = b

# Global variables for various parameters
n = 0 # Dimension or count
h = 0 # Height
w = 0 # Width
k = 0 # Some parameter
q = 0 # Query count
va = 0 # Signed long long variable
vb = 0 # Signed long long variable
vc = 0 # Signed long long variable
vd = 0 # Signed long long variable
ve = 0 # Signed long long variable
vf = 0 # Signed long long variable
ua = 0 # Unsigned long long variable
ub = 0 # Unsigned long long variable
uc = 0 # Unsigned long long variable
ud = 0 # Unsigned long long variable
ue = 0 # Unsigned long long variable
uf = 0 # Unsigned long long variable
vra = 0.0 # Long double variable
vrb = 0.0 # Long double variable
vrc = 0.0 # Long double variable
vda = 0.0 # Double variable
vdb = 0.0 # Double variable
vdc = 0.0 # Double variable
ch = 0 # Character variable
dh = 0 # Character variable

# Function to return the minimum of two unsigned long long integers
def umin(a, b):
    return min(a, b)

# Function to return the maximum of two unsigned long long integers
def umax(a, b):
    return max(a, b)

# Function to return the minimum of two signed long long integers
def smin(a, b):
    return min(a, b)

# Function to return the maximum of two signed long long integers
def smax(a, b):
    return max(a, b)

# Function to compute the greatest common divisor (GCD) of two unsigned long long integers
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

# Function to compute a^x mod modulo using binary exponentiation
def bitpow(a, x, modulo):
    result = 1
    while x:
        if x & 1:
            result = (result * a) % modulo
        x //= 2
        a = (a * a) % modulo
    return result

# Function to perform modular division a / b mod modulo
def divide(a, b, modulo):
    return (a * bitpow(b, modulo - 2, modulo)) % modulo

# Function to return the absolute difference between two unsigned long long integers
def udiff(a, b):
    if a >= b:
        return a - b
    else:
        return b - a

# Function to return the absolute difference between two signed long long integers
def sdiff(a, b):
    if a >= b:
        return a - b
    else:
        return b - a

# Function to count the number of set bits in an unsigned long long integer
def bitcount(n):
    count = 0
    while n:
        if n & 1:
            count += 1
        n //= 2
    return count

# Macros for comparison functions
def pullcomp(left, right):
    l = left
    r = right
    if l < r:
        return -1
    elif l > r:
        return 1
    else:
        return 0

def prevcomp(left, right):
    l = left
    r = right
    if l > r:
        return -1
    elif l < r:
        return 1
    else:
        return 0

def psllcomp(left, right):
    l = left
    r = right
    if l < r:
        return -1
    elif l > r:
        return 1
    else:
        return 0

def pcharcomp(left, right):
    l = left
    r = right
    if l < r:
        return -1
    elif l > r:
        return 1
    else:
        return 0

def pdoublecomp(left, right):
    l = left
    r = right
    if l < r:
        return -1
    elif l > r:
        return 1
    else:
        return 0

# Comparison function for strings
def pstrcomp(left, right):
    l = left
    r = right
    return (l < r) - (l > r)

# Comparison function for hwll structures based on fields a and b
def phwllABcomp(left, right):
    l = left
    r = right
    if l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.b < r.b:
        return -1
    elif l.b > r.b:
        return 1
    elif l.c < r.c:
        return -1
    elif l.c > r.c:
        return 1
    else:
        return 0

# Comparison function for hwll structures in reverse order
def phwllREVcomp(left, right):
    l = left
    r = right
    if l.b < r.b:
        return -1
    elif l.b > r.b:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.c < r.c:
        return -1
    elif l.c > r.c:
        return 1
    elif l.b < r.b:
        return -1
    elif l.b > r.b:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
        return 1
    elif l.a < r.a:
        return -1
    elif l.a > r.a:
  