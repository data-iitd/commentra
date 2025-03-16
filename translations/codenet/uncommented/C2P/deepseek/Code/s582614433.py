import sys

# Define the Edge structure
class Edge:
    def __init__(self, p, s, i):
        self.p = p
        self.s = s
        self.i = i

# Read input
n = int(input())
data = [Edge(0, '', 0) for _ in range(n)]

for i in range(n):
    s, p = input().split()
    p = int(p)
    data[i] = Edge(p, s, i)

# Sort the edges based on the specified criteria
data.sort(key=lambda edge: (edge.s, -edge.p))

# Print the indices
for edge in data:
    print(edge.i + 1)

# End-of-code comment
print("<END-OF-CODE>")