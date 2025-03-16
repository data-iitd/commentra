
import sys

# Define a long long integer type for convenience
ll = int

# Define a macro for a simple loop
def rep(i, l, r):
    for i in range(l, r):

# Define a macro for a loop with a step
def repp(i, l, r, k):
    for i in range(l, r, k):

# Define a large number to represent infinity
INF = (1 << 62) - (1 << 31)

# Define a macro to get the maximum of two values
def max(p, q):
    return p if p > q else q

# Define a macro to get the minimum of two values
def min(p, q):
    return p if p < q else q

# Define a macro to check if a bit is set in a number
def bit(n, m):
    return (n >> m) & 1

# Function to sort in ascending order
def upll(a, b):
    return a < b

# Function to sort in descending order
def downll(a, b):
    return a > b

# Function to sort an array of long long values in ascending order using sort
def sortup(a):
    a.sort(key=upll)

# Function to sort an array of long long values in descending order using sort
def sortdown(a):
    a.sort(key=downll, reverse=True)

# Function to perform modular exponentiation
def pom(a, n, m):
    x = 1
    a %= m
    while n:
        if n & 1:
            x = x * a % m
        a = a * a % m
        n //= 2
    return x

# Define a modulo value
MOD = 1000000007

# Function to compute the modular multiplicative inverse
def invp(a, p):
    return pom(a, p - 2, p)

# Define a structure to hold edge information
class Edge:
    def __init__(self, p, i, s):
        self.p = p
        self.i = i
        self.s = s

# Function to sort edges based on the string and then by the long long value
def esort(a, b):
    cmp = a.s.cmp(b.s)
    if cmp:
        return cmp
    if a.p < b.p:
        return 1
    return -1

# Array to hold edge data
edges = []

# Variables to hold the number of edges
n = ll(input())

# Read each edge's string and long long value, and store the index
for i in range(n):
    s, p = input().split()
    p = ll(p)
    edges.append(Edge(p, i + 1, s))

# Sort the edges using sort and the custom esort function
edges.sort(key=lambda x: (x.s, x.p))

# Print the indices of the edges in the sorted order
for edge in edges:
    print(edge.i)

