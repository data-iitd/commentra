import sys
from functools import cmp_to_key

# Define a large prime number for modulo operations
MOD = 1000000007

# Structure to hold edge information
class Edge:
    def __init__(self, weight, index, identifier):
        self.p = weight  # Weight or value associated with the edge
        self.i = index    # Index of the edge
        self.s = identifier  # Name or identifier of the edge

# Comparison function for sorting edges
def esort(edge1, edge2):
    # First compare by string identifier
    if edge1.s != edge2.s:
        return (edge1.s > edge2.s) - (edge1.s < edge2.s)  # Sort by string
    # If identifiers are the same, compare by weight in descending order
    return (edge1.p < edge2.p) - (edge1.p > edge2.p)

def main():
    # Read the number of edges
    n = int(sys.stdin.readline().strip())
    
    # Array to hold edge data
    data = []
    
    # Read edge data from input
    for i in range(n):
        line = sys.stdin.readline().strip().split()
        identifier = line[0]
        weight = int(line[1])
        data.append(Edge(weight, i, identifier))  # Create Edge object and append to list
    
    # Sort the edges based on the defined sorting criteria
    data.sort(key=cmp_to_key(esort))
    
    # Output the original indices of the sorted edges
    for edge in data:
        print(edge.i + 1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
