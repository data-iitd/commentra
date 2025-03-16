import sys
from collections import defaultdict

class MyScanner:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        value = self.data[self.index]
        self.index += 1
        return value

    def next_int(self):
        return int(self.next())

def max_matching(v, p):
    a = 0  # Number of matched pairs
    o = 0  # Number of unmatched nodes
    for w in g[v]:
        if w == p:
            continue  # Skip the parent node
        r = max_matching(w, v)  # Recursively calculate matching for child nodes
        a += r // 2  # Add half of the matches from the child
        o += r % 2  # Count the unmatched nodes
    return 2 * a + min(1, o) + 1  # Return the total number of matches

# Main execution
sc = MyScanner()  # Create a scanner object to read input
n = sc.next_int()  # Read the number of nodes
g = defaultdict(list)  # Initialize the graph's adjacency list

for _ in range(n - 1):  # Read the edges and construct the graph
    a = sc.next_int() - 1  # Read node a and convert to 0-based index
    b = sc.next_int() - 1  # Read node b and convert to 0-based index
    g[a].append(b)  # Add edge from a to b
    g[b].append(a)  # Add edge from b to a

m = max_matching(0, -1) // 2  # Calculate the maximum matching
print("Second" if 2 * m == n else "First")  # Determine the winner and print the result

# <END-OF-CODE>
