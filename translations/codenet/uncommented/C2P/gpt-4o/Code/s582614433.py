import sys
from functools import cmp_to_key

MOD = 1000000007

class Edge:
    def __init__(self, s, p, i):
        self.s = s
        self.p = p
        self.i = i

def edge_sort(a, b):
    if a.s != b.s:
        return (a.s > b.s) - (a.s < b.s)  # Sort by string
    return (a.p < b.p) - (a.p > b.p)  # Sort by value in descending order

n = int(sys.stdin.readline().strip())
data = []

for i in range(n):
    s, p = sys.stdin.readline().strip().split()
    p = int(p)
    data.append(Edge(s, p, i))

data.sort(key=cmp_to_key(edge_sort))

for edge in data:
    print(edge.i + 1)

# <END-OF-CODE>
