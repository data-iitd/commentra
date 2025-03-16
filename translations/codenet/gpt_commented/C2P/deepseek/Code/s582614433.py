import sys

# Define long long type for convenience
ll = int

# Macro for iterating from l to r
def rep(i, l, r):
    while l < r:
        yield i(l)
        l += 1

# Macro for iterating from l to r with step k
def repp(i, l, r, k):
    while l < r:
        yield i(l)
        l += k

# Define a large constant for infinity
INF = (1 << 62) - (1 << 31)

# Macro to get the maximum of two values
def max(p, q):
    return p if p > q else q

# Macro to get the minimum of two values
def min(p, q):
    return p if p < q else q

# Macro to check the bit at position m in n
def bit(n, m):
    return (n >> m) & 1

# Comparison function for sorting in ascending order
def upll(a, b):
    return a < b

# Comparison function for sorting in descending order
def downll(a, b):
    return a > b

# Function to sort an array in ascending order
def sortup(a, n):
    a.sort()

# Function to sort an array in descending order
def sortdown(a, n):
    a.sort(reverse=True)

# Function to compute (a^n) % m using modular exponentiation
def pom(a, n, m):
    x = 1
    a %= m
    while n:
        if n & 1:
            x = x * a % m
        a = a * a % m
        n //= 2
    return x

# Define a large prime number for modulo operations
MOD = 1000000007

# Macro to compute modular inverse using Fermat's little theorem
def invp(a, p):
    return pom(a, p - 2, p)

# Structure to hold edge information
class Edge:
    def __init__(self, p, i, s):
        self.p = p
        self.i = i
        self.s = s

# Comparison function for sorting edges
def esort(a, b):
    p = a
    q = b
    # First compare by string identifier
    if p.s != q.s:
        return -1 if p.s < q.s else 1
    # If identifiers are the same, compare by weight in descending order
    if p.p < q.p:
        return 1
    return -1

# Array to hold edge data
data = []
n = 0
m = 0

# Read the number of edges
n = int(input())

# Read edge data from input
for i in range(n):
    s, p = input().split()
    p = int(p)
    data.append(Edge(p, i, s))

# Sort the edges based on the defined sorting criteria
data.sort(key=lambda x: (x.s, -x.p))

# Output the original indices of the sorted edges
for edge in data:
    print(edge.i + 1)

