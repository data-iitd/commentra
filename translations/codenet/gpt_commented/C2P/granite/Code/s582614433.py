
import sys

# Define long long type for convenience
int64 = int

# Define a large constant for infinity
INF = int(1e18)

# Define a large prime number for modulo operations
MOD = 1000000007

# Function to compute (a^n) % m using modular exponentiation
def pom(a, n, m):
    x = 1 # Initialize result
    while n:
        n //= 2
        if n % 2: x = x * a % m # If n is odd, multiply x by a
        a = a * a % m # Square a
    return x # Return the result

# Define a large prime number for modulo operations
MOD = 1000000007

# Function to compute modular inverse using Fermat's little theorem
def invp(a, p):
    return pom(a, p - 2, p)

# Structure to hold edge information
class Edge:
    def __init__(self, p, i, s):
        self.p = p # Weight or value associated with the edge
        self.i = i # Index of the edge
        self.s = s # Name or identifier of the edge

# Comparison function for sorting edges
def esort(a, b):
    # First compare by string identifier
    if a.s < b.s: return -1
    if a.s > b.s: return 1
    # If identifiers are the same, compare by weight in descending order
    if a.p < b.p: return 1
    return -1 # Otherwise, return -1 for sorting

# Read the number of edges
n = int(input())

# Read edge data from input
edges = []
for i in range(n):
    s, p = input().split()
    edges.append(Edge(int(p), i, s)) # Read string and weight

# Sort the edges based on the defined sorting criteria
edges.sort(key=lambda x: (x.s, -x.p))

# Output the original indices of the sorted edges
for edge in edges:
    print(edge.i + 1)

