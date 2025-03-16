

import sys

# Constants and macro definitions
BIG = 2000000007
VERYBIG = 20000000000000007
MOD = 1000000007
FOD = 998244353
N_MAX = 1048576

# Data type and structure definitions
class hwll:
    def __init__(self, a, b):
        self.a = a
        self.b = b

class hwllc:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

class hwreal:
    def __init__(self, a, b):
        self.a = a
        self.b = b

# Variable declarations
n = 4
m = 0
h = 0
w = 0
k = 0
q = 0
va = 0
vb = 0
vc = 0
vd = 0
ve = 0
vf = 0
ua = 0
ub = 0
uc = 0
ud = 0
ue = 0
uf = 0
vra = 0.0
vrb = 0.0
vrc = 0.0
vda = 0.0
vdb = 0.0
vdc = 0.0
ch = ''
dh = ''

# Helper function declarations
def umin(a, b):
    return min(a, b)

def umax(a, b):
    return max(a, b)

def smin(a, b):
    return min(a, b)

def smax(a, b):
    return max(a, b)

def gcd(a, b):
    while b!= 0:
        a, b = b, a % b
    return a

def bitpow(a, x, modulo):
    result = 1
    while x > 0:
        if x % 2 == 1:
            result = (result * a) % modulo
        a = (a * a) % modulo
        x //= 2
    return result

def divide(a, b, modulo):
    return (a * bitpow(b, modulo - 2, modulo)) % modulo

def udiff(a, b):
    return abs(a - b)

def bitcount(n):
    count = 0
    while n > 0:
        count += n % 2
        n //= 2
    return count

# Function declarations
def pullcomp(left, right):
    return left[0] - right[0]

def prevcomp(left, right):
    return left[0] - right[0]

def psllcomp(left, right):
    return left[0] - right[0]

def pcharcomp(left, right):
    return ord(left) - ord(right)

def pdoublecomp(left, right):
    return left - right

def pstrcomp(left, right):
    return left - right

def phwllABcomp(left, right):
    return left.a - right.a

def phwllREVcomp(left, right):
    return left.a - right.a

def ptriplecomp(left, right):
    return left.a - right.a

def ptripleREVcomp(left, right):
    return left.a - right.a

def ptripleCABcomp(left, right):
    return left.a - right.a

def pquadcomp(left, right):
    return left.a - right.a

def pfracomp(left, right):
    return left.a - right.a

def isinrange(left, x, right):
    return left <= x <= right

def isinrange_soft(left, x, right):
    return left < x < right

def sw(l, r):
    l, r = r, l
    return l, r

def ncr(n, r, m):
    numerator = 1
    denominator = 1
    for i in range(r):
        numerator = (numerator * (n - i)) % m
        denominator = (denominator * (i + 1)) % m
    return (numerator * divide(1, denominator, m)) % m

# Main function implementation
def main():
    i = 0
    j = 0

    # Initialize variables
    n = 4
    m = 0

    # Read input values
    q = int(input())
    a = [0] * n
    b = [0] * n
    c = [0] * m

    for i in range(n):
        b[i] = int(input())

    for i in range(m):
        c[i] = int(input())

    result = 1
    for i in range(n * 3):
        v = ord(input()) - ord('R')
        if cnt[(v + 1) % 3] and cnt[(v + 2) % 3]:
            result *= (cnt[(v + 1) % 3] * cnt[(v + 2) % 3] % FOD)
            pcnt -= 1
            result %= FOD
            cnt[(v + 1) % 3] -= 1
            cnt[(v + 2) % 3] -= 1
        else:
            if (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]:
                result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v]
                result %= FOD
                pcnt += 1
            cnt[v] += 1

    for i in range(1, n + 1):
        result = (result * i) % FOD

    print(result)

if __name__ == "__main__":
    main()
