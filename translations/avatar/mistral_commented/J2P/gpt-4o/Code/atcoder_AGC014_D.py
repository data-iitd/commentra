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
    a = 0  # Number of edges matched from the neighboring vertices of 'v'
    o = 0  # Number of vertices that have odd degree (unmatched vertices) in the neighboring vertices of 'v'

    # Iterating through all the neighbors of 'v'
    for w in g[v]:
        if w == p:
            continue  # Skip if the neighbor is 'p' (self-loop)

        # Recursively calling the function for the neighbor 'w' and updating the values of 'a' and 'o'
        r = max_matching(w, v)
        a += r // 2
        o += r % 2

    # Returning the result based on the parity of 'o'
    return 2 * a + min(1, o)

# Main function
if __name__ == "__main__":
    sc = MyScanner()  # Creating an instance of MyScanner class for reading input

    # Reading the number of vertices in the graph
    n = sc.next_int()

    # Initializing the graph as a defaultdict of lists
    g = defaultdict(list)

    # Reading the edges and adding them to the graph
    for _ in range(n - 1):
        a = sc.next_int() - 1  # Reading the first vertex of the edge
        b = sc.next_int() - 1  # Reading the second vertex of the edge
        g[a].append(b)  # Adding the edge from 'a' to 'b'
        g[b].append(a)  # Adding the edge from 'b' to 'a'

    # Finding the maximum number of edges that can be matched in the graph
    max_matching_result = max_matching(0, -1) // 2

    # Printing the result based on whether all vertices have even degree or not
    print("Second" if 2 * max_matching_result == n else "First")

# <END-OF-CODE>
