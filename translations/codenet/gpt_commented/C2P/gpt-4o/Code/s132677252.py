import sys
from collections import deque

# Define a constant for modulo operations
mod = 1000000007

# Function to compute modular exponentiation
def mod_pow(r, n):
    t = 1  # Result variable
    s = r  # Base
    # Loop until the exponent is zero
    while n > 0:
        if n & 1:
            t = (t * s) % mod  # If n is odd, multiply the result by the base
        s = (s * s) % mod  # Square the base
        n >>= 1  # Divide n by 2
    return t  # Return the result

# Structure to represent a node in dynamic programming
class Node:
    def __init__(self, one=0, zero=0):
        self.one = one  # Count of paths ending with 1
        self.zero = zero  # Count of paths ending with 0

# Function to merge multiple dp nodes
def merge(a):
    one = 0  # Initialize count of paths ending with 1
    zero = 1  # Initialize count of paths ending with 0
    total = 1  # Initialize total paths
    # Iterate through the nodes to merge their counts
    for node in a:
        one = (one * node.zero + zero * node.one) % mod  # Update count of paths ending with 1
        zero = (zero * node.zero) % mod  # Update count of paths ending with 0
        total = (total * (node.zero + node.one)) % mod  # Update total paths
    return Node(one, (total + mod - one) % mod)  # Return merged node

# Main function to run the algorithm
def run():
    n = int(sys.stdin.readline().strip())  # Read the number of vertices
    p = [0] * (n + 1)  # Parent array
    depth = [0] * (n + 1)  # Depth array
    cnt = [0] * (n + 1)  # Count array
    cnt[0] = 1  # Initialize count for depth 0
    graph = [[] for _ in range(n + 1)]  # Create a graph as an adjacency list

    # Read edges and build the graph
    for i in range(1, n + 1):
        p[i] = int(sys.stdin.readline().strip())  # Read parent for vertex i
        graph[p[i]].append(i)  # Add edge from parent to current vertex
        depth[i] = depth[p[i]] + 1  # Update depth of current vertex
        cnt[depth[i]] += 1  # Increment count for the current depth

    dp = [deque() for _ in range(n + 1)]  # Dynamic programming arrays
    lst = [Node() for _ in range(n + 1)]  # List to store nodes

    # Process vertices in reverse order
    for v in range(n, -1, -1):
        # If the vertex has no outgoing edges
        if not graph[v]:
            dp[v].append(Node(1, 1))  # Initialize with base case
            continue

        child = []  # List to store child deques
        # Collect child deques for the current vertex
        for u in graph[v]:
            child.append(dp[u])  # Store child deque

        # If there are multiple child deques, merge them
        if len(child) > 1:
            child.sort(key=len, reverse=True)  # Sort child deques by size
            # Merge the child deques
            for d in range(len(child[1])):
                lst = [Node() for _ in range(len(child))]
                for j in range(len(child)):
                    if d < len(child[j]):
                        lst[j] = child[j][d]  # Get nodes from child deques
                dp[child[0]].append(merge(lst))  # Merge and assign to the first child

            # Free the other child deques (handled by Python's garbage collection)

        dp[v].append(Node(1, 1))  # Add the base case to the front

    ans = 0  # Variable to store the final answer
    # Calculate the final answer based on the dp values
    for i in range(len(dp[0])):
        ans += (mod_pow(2, n + 1 - cnt[i]) * dp[0][i].one) % mod  # Update answer

    print(ans % mod)  # Print the final answer

# Main function to execute the program
if __name__ == "__main__":
    run()  # Call the run function

# <END-OF-CODE>
