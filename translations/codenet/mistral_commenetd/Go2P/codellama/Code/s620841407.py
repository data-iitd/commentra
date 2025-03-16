
import sys
input = sys.stdin.readline

# Read input: number of nodes and edges
n, m = map(int, input().split())
edges = []
for i in range(n-1):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    edges.append([x, y])

# Initialize the disjoint set data structure
def f(x, y):
    return x * y % m

def g(v, p):
    return v + 1

s = ReRootingSolver(n, edges, 1, f, g)

# Query the product of subtrees for all nodes and print the result
for i in range(n):
    print(s.query(i) - 1)

